#ifndef __SYLAR_SCHEDULER_H__
#define __SYLAR_SCHEDULER_H__

#include <memory>
#include <vector>
#include <list>
#include "fiber.h"
#include "thread.h"

namespace sylar{

class Scheduler{
public:
    using ptr = std::shared_ptr<Scheduler>;
    using MutexType = Mutex;

    Scheduler(size_t threads = 1, bool use_caller = true, const std::string& name = "");
    virtual ~Scheduler();

    const std::string& getName() const{return m_name;}

    static Scheduler* GetThis();
    static Fiber* GetMainFiber();

    void start();
    void stop();

    template<class FiberOrCb>
    void schedule(FiberOrCb fc, int thread = -1){
        bool need_tickle = false;
        {
            MutexType::Lock lock(m_mutex);
            need_tickle = scheduleNoLock(fc, thread);
        }

        if(need_tickle){
            tickle();
        }
    }

    template<class InputIterator>
    void schedule(InputIterator begin, InputIterator end){
        bool need_tickle = false;
        {
            MutexType::Lock lock(m_mutex);
            while(begin != end){ 
                need_tickle = scheduleNoLock(&*begin, -1) || need_tickle;
                ++begin;
            }
        }
        if(need_tickle){
            tickle();
        }
    }
protected:
    virtual void tickle();
    void run();
    virtual bool stopping();
    virtual void idle();

    void setThis();

    bool hasIdleThreads() {return m_idleThreadCount > 0;}
private:
    template<class FiberOrCb>
    bool scheduleNoLock(FiberOrCb fc, int thread){
        bool need_tickle = m_fibers.empty();
        FiberAndThread ft(fc, thread);
        if(ft.fiber || ft.cb){
            m_fibers.push_back(ft);
        }
        return need_tickle;
    }
private:
    struct FiberAndThread{
        Fiber::ptr fiber;
        std::function<void()> cb;
        int thread;
/*  智能指针本质上是使用局部变量生命周期管理堆内存
第一个直接传递智能指针对象，该对象肯定实在栈上，栈上的局部变量只要执行到花括号就会释放
所以第一个不需要swap，局部变量会自动析构，引用计数自动-1
但是第二个传递的是智能指针对象的指针，智能指针对象本身在堆区，不会自动调用析构
也就是说第二个函数，只要外部没有由程序员主动析构，引用计数至少为1   */
//但是一般不推荐这样搞，最好不要试图接管外部传递过来的指针的生命周期
        FiberAndThread(Fiber::ptr f, int thr)
            :fiber(f), thread(thr){}

        FiberAndThread(Fiber::ptr* f, int thr)
            :thread(thr){
                fiber.swap(*f);
        }

        FiberAndThread(std::function<void()> f, int thr)
            :cb(f), thread(thr){
        }

        FiberAndThread(std::function<void()>* f, int thr)
            :thread(thr){
                cb.swap(*f);
        }

        FiberAndThread() : thread(-1) {}

        void reset(){
            fiber = nullptr;
            cb = nullptr;
            thread = -1;
        }
    };
private:
    MutexType m_mutex;
    std::vector<Thread::ptr> m_threads;
    std::list<FiberAndThread> m_fibers;
    Fiber::ptr m_rootFiber;
    std::string m_name;
protected:
    std::vector<int> m_threadIds;
    size_t m_threadCount = 0;
    std::atomic<size_t> m_activeThreadCount = {0};
    std::atomic<size_t> m_idleThreadCount = {0};
    bool m_stopping = true;
    bool m_autoStop = false;
    int m_rootThread = 0;
};

}

#endif