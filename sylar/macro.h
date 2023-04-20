#ifndef __SYLAR_MACRO_H__
#define __SYLAR_MACRO_H__

#include <string.h>
#include <assert.h>
#include "util.h"

/*
定义了两个宏 SYLAR_LICKLY 和 SYLAR_UNLICKLY，用于提高代码的分支预测能力，从而提高程序的性能。
在代码中，通过预定义 GUNC 或 llvm 宏来判断当前代码所使用的编译器是否支持 __builtin_expect 函数，该函数的作用是告诉编译器分支预测的结果，进而优化代码执行效率。
如果编译器支持 __builtin_expect 函数，则将 SYLAR_LICKLY 和 SYLAR_UNLICKLY 宏的定义替换为 __builtin_expect(!!(x), 1) 和 __builtin_expect(!!(x), 0)，分别表示将x的结果视为真或假的可能性更大，从而提高对x的分支预测能力。
如果编译器不支持 __builtin_expect 函数，则 SYLAR_LICKLY 和 SYLAR_UNLICKLY 宏的定义将简单地返回x本身，即不进行分支预测优化。
*/
#if defined __GUNC__ || defined __llvm__
#   define SYLAR_LICKLY(x)     __builtin_expect(!!(x), 1)
#   define SYLAR_UNLICKLY(x)   __builtin_expect(!!(x), 0)
#else
#   define SYLAR_LICKLY(x)     (x)
#   define SYLAR_UNLICKLY(x)     (x)
#endif

#define SYLAR_ASSERT(x) \
    if(SYLAR_UNLICKLY(!(x))){ \
        SYLAR_LOG_ERROR(SYLAR_LOG_ROOT()) << "ASSERTION: " #x \
            << "\nbacktrace:\n" \
            << sylar::BacktraceToString(100, 2, "    "); \
        assert(x); \
    }

#define SYLAR_ASSERT2(x, w) \
    if(SYLAR_UNLICKLY(!(x))){ \
        SYLAR_LOG_ERROR(SYLAR_LOG_ROOT()) << "ASSERTION: " #x \
            << "\n" << w \
            << "\nbacktrace:\n" \
            << sylar::BacktraceToString(100, 2, "    "); \
        assert(x); \
    }

#endif