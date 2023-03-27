#include "scheduler.h"
#include "log.h"
#include "macro.h"

namespace sylar{
static sylar::Logger::ptr g_logger = SYLAR_LOG_NAME("system");

static thread_local Scheduler* t_scheduler = nullptr;
static thread_local Fiber* t_fiber = nullptr;

Scheduler::Scheduler(size_t threads, bool use_caller, const std::string& name) : m_name(name){
    SYLAR_ASSERT(threads > 0);
    if(use_caller){
        sylar::Fiber::GetThis(); //若该线程没有协程，GetThis初始化一个主协程
        --threads;

        SYLAR_ASSERT(GetThis() == nullptr);
        t_scheduler = this;

        m_rootFiber.reset(new Fiber(std::bind(&Scheduler::run, this), 0, true));
        sylar::Thread::SetName(m_name);
//这个地方的关键点在于，是否把创建协程调度器的线程放到协程调度器管理的线程池中。如果不放入，那这个线程专职协程调度；如果放的话，那就要把协程调度器封装到一个协程中，称之为主协程或协程调度器协程。
        t_fiber = m_rootFiber.get();
        m_rootThread = sylar::GetThreadId();
        m_threadIds.push_back(m_rootThread);
    }else{
        m_rootThread = -1;
    }
    m_threadCount = threads;
}

Scheduler::~Scheduler(){
    SYLAR_ASSERT(m_stopping);
    if(GetThis() == this){
        t_scheduler = nullptr;
    }
}

Scheduler* Scheduler::GetThis(){
    return t_scheduler;
}

Fiber* Scheduler::GetMainFiber(){
    return t_fiber;
}

void Scheduler::start(){
    MutexType::Lock lock(m_mutex);
    if(!m_stopping){
        return;
    }
    m_stopping = false;
    SYLAR_ASSERT(m_threads.empty());

    m_threads.resize(m_threadCount);
    for(size_t i = 0; i < m_threadCount; ++i){
        m_threads[i].reset(new Thread(std::bind(&Scheduler::run, this)
                            , m_name + "_" + std::to_string(i)));
        m_threadIds.push_back(m_threads[i]->getId());
    }
    lock.unlock();
/*
这里原因的本质是协程调度器管理的主协程s和创建协程时候设置的主协程f不一致造成的
所以如果用swapin，就把当前f的上下文存入了s，再执行s，此时f和s其实是一样的
此时f和s都是创建协程时候设置的主协程f，协程管理器设置的s其实被f覆盖了
导致进不去run，同时协程f一直没有该变state，就报错了
*/
    //if(m_rootFiber){
        //SetThis(this);
        //m_rootFiber->swapIn();
        //m_rootFiber->call();
        //SYLAR_LOG_INFO(g_logger) << "call out" << m_rootFiber->getState();
    //}
}

void Scheduler::stop(){
    m_autoStop = true;
    if(m_rootFiber && m_threadCount == 0 && (m_rootFiber->getState() == Fiber::TERM || m_rootFiber->getState() == Fiber::INIT)){
        SYLAR_LOG_INFO(g_logger) << this << " stopped";
        m_stopping = true;

        if(stopping()){
            return;
        }
    }

    //bool exit_on_this_fiber = false;
    if(m_rootThread != -1){
        SYLAR_ASSERT(GetThis() == this);
    }else{
        SYLAR_ASSERT(GetThis() != this);
    }

    m_stopping = true;
    for(size_t i = 0; i < m_threadCount; ++i){
        tickle();
    }

    if(m_rootFiber){
        tickle();
    }

    if(m_rootFiber){
        while(!stopping()) {
            //if(m_rootFiber->getState() == Fiber::TERM
            //        || m_rootFiber->getState() == Fiber::EXCEPT) {
            //    m_rootFiber.reset(new Fiber(std::bind(&Scheduler::run, this), 0, true));
            //    SYLAR_LOG_INFO(g_logger) << " root fiber is term, reset";
            //    t_fiber = m_rootFiber.get();
            //}
            //m_rootFiber->call();
            if(!stopping()){
                m_rootFiber->call();
            }
        }
    }

    std::vector<Thread::ptr> thrs;
    {
        MutexType::Lock lock(m_mutex);
        thrs.swap(m_threads);
    }

    for(auto& i : thrs) {
        i->join();
    }
    //if(exit_on_this_fiber){
    //}
}

void Scheduler::setThis(){
    t_scheduler = this;
}

void Scheduler::run(){
    SYLAR_LOG_INFO(g_logger) << "run";
    setThis();
    if(sylar::GetThreadId() != m_rootThread){
        t_fiber = Fiber::GetThis().get();
    }

    Fiber::ptr idle_fiber(new Fiber(std::bind(&Scheduler::idle, this)));
    Fiber::ptr cb_fiber;

    FiberAndThread ft;
    while(true){
        ft.reset();
        bool tickle_me = false;
        bool is_active = false;
        {
            MutexType::Lock lock(m_mutex);
            auto it = m_fibers.begin();
            while(it != m_fibers.end()){
                if(it->thread != -1 && it->thread != sylar::GetThreadId()){
                    ++it;
                    tickle_me = true;
                    continue;
                }

                SYLAR_ASSERT(it->fiber || it->cb);
                if(it->fiber && it->fiber->getState() == Fiber::EXEC){
                    ++it;
                    continue;
                }

                ft = *it;
                m_fibers.erase(it);
                ++m_activeThreadCount;
                is_active = true;
                break;
            }
        }

        if(tickle_me){
            tickle();
        }

        if(ft.fiber && (ft.fiber->getState() != Fiber::TERM
                        && ft.fiber->getState() != Fiber::EXCEPT)){
            ft.fiber->swapIn();
            --m_activeThreadCount;

            if(ft.fiber->getState() == Fiber::READY){
                schedule(ft.fiber);
            }else if(ft.fiber->getState() != Fiber::TERM && ft.fiber->getState() != Fiber::EXCEPT){
                ft.fiber->m_state = Fiber::HOLD;
            }
            ft.reset();
        }else if(ft.cb){
            if(cb_fiber){
                cb_fiber->reset(ft.cb);
            }else{
                cb_fiber.reset(new Fiber(ft.cb));
            }
            ft.reset();
            cb_fiber->swapIn();
            --m_activeThreadCount;
            if(cb_fiber->getState() == Fiber::READY){
                schedule(cb_fiber);
                cb_fiber.reset();
            }else if(cb_fiber->getState() == Fiber::EXCEPT || cb_fiber->getState() == Fiber::TERM){
                cb_fiber->reset(nullptr);
            }else {//if(cb_fiber->getState() != Fiber::TERM){
                cb_fiber->m_state = Fiber::HOLD;
                cb_fiber.reset();
            }
        }else{
            if(is_active){
                --m_activeThreadCount;
                continue;
            }
            if(idle_fiber->getState() == Fiber::TERM){
                SYLAR_LOG_INFO(g_logger) << "idle fiber term";
                //tickle();
                break;
            }

            ++m_idleThreadCount;
            idle_fiber->swapIn();
            --m_idleThreadCount;
            if(idle_fiber->getState() != Fiber::TERM && idle_fiber->getState() != Fiber::EXCEPT){ //|| 改为 &&
                idle_fiber->m_state = Fiber::HOLD;
            }
        }
    }

}
/*
run()函数
1. 设置当前线程的scheduler
2. 设置当前线程的run Fiber
3. 协程调度循环while(true)
    * 协程消息队列里面是否有任务
    * 无任务执行idle
*/

void Scheduler::tickle(){
    SYLAR_LOG_INFO(g_logger) << "tickle";
}

bool Scheduler::stopping(){
    MutexType::Lock lock(m_mutex);
    return m_autoStop && m_stopping && m_fibers.empty() && m_activeThreadCount == 0;
}

void Scheduler::idle(){
    SYLAR_LOG_INFO(g_logger) << "idle";
    while(!stopping()){
        sylar::Fiber::YieldToHold();
    }
}

}
