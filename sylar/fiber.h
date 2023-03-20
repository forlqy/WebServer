#ifndef __SYLAR_FIBER_H__
#define __SYLAR_FIBER_H__

#include <memory>
#include <functional>
#include <ucontext.h>
#include "thread.h"

namespace sylar{

class Fiber : public std::enable_shared_from_this<Fiber>{ //继承enable_shared_from_this类后就不可以在栈上创建成员
public:
    std::shared_ptr<Fiber> ptr;

    enum State{
        INIT,
        HOLD,
        EXEC,
        TERM,
        READY
    };
private:
    Fiber();
public:
    Fiber(std::function<void()> cb, size_t stacksize = 0);
    ~Fiber();
    //重置协程函数和状态
    //INIT，TERM
    void reset(std::function<void()> cb);
    //切换到当前协程执行
    void swapIn();
    //切换到后台执行
    void swapOut();
public:
    //返回当前协程
    static Fiber::ptr GetThis();
    //协程切换到后台，并设置为Ready状态
    static void YieldToReady();
    //协程切换到后台，并设置为Hold状态
    static void YieldToHold();
    //总协程数
    static uint64_t TotalFibers();
};

}

#endif