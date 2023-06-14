/*这是在写单例模式的模板类
之所以不在日志管理器里面实现单例模式，以为分布式多线程等可能是每个线程一个单例
使用模板就可以解决这类问题
*/

#ifndef __SYLAR_SINGLETON_H__
#define __SYLAR_SINGLETON_H__

#include <memory>

namespace sylar {

template<class T, class X = void, int N = 0>
class Singleton {
public:
    static T* GetInstance() {
        static T v;
        return &v;
    }
};

template<class T, class X = void, int N = 0>
class SingletonPtr {
public:
    static std::shared_ptr<T> GetInstance() {
        static std::shared_ptr<T> v(new T);
        return v;
    }
};

}

#endif








/*
 这里使用模板类实现单例，日志管理器本身不是单例，模板类是一个提供的单例构造器，只要静态方法就行了
 构造的单例类的构造函数不能私有，因为模板类静态函数需要调用
  */
