#ifndef SYSCALL_STATIC

#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

static __inline long __syscall0(long n)
{
    unsigned long ret;
    __asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n) : "rcx", "r11", "memory");
    return ret;
}

static __inline long __syscall1(long n, long a1)
{
    unsigned long ret;
    __asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1) : "rcx", "r11", "memory");
    return ret;
}

static __inline long __syscall2(long n, long a1, long a2)
{
    unsigned long ret;
    __asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2)
                          : "rcx", "r11", "memory");
    return ret;
}

static __inline long __syscall3(long n, long a1, long a2, long a3)
{
    unsigned long ret;
    __asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2),
                          "d"(a3) : "rcx", "r11", "memory");
    return ret;
}

static __inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
    unsigned long ret;
    register long r10 __asm__("r10") = a4;
    __asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2),
                          "d"(a3), "r"(r10): "rcx", "r11", "memory");
    return ret;
}

static __inline long __syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
    unsigned long ret;
    register long r10 __asm__("r10") = a4;
    register long r8 __asm__("r8") = a5;
    __asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2),
                          "d"(a3), "r"(r10), "r"(r8) : "rcx", "r11", "memory");
    return ret;
}

static __inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
    unsigned long ret;
    register long r10 __asm__("r10") = a4;
    register long r8 __asm__("r8") = a5;
    register long r9 __asm__("r9") = a6;
    __asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2),
                          "d"(a3), "r"(r10), "r"(r8), "r"(r9) : "rcx", "r11", "memory");
    return ret;
}

#else

#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

static inline long __syscall0(long n)
{
    long (*fn)(long,long,long,long,long,long) = (long (*)(long,long,long,long,long,long))n;
    return fn(0,0,0,0,0,0);
}

static inline long __syscall1(long n, long a1)
{
    long (*fn)(long,long,long,long,long,long) = (long (*)(long,long,long,long,long,long))n;
    return fn(a1,0,0,0,0,0);
}

static inline long __syscall2(long n, long a1, long a2)
{
    long (*fn)(long,long,long,long,long,long) = (long (*)(long,long,long,long,long,long))n;
    return fn(a1,a2,0,0,0,0);
}

static inline long __syscall3(long n, long a1, long a2, long a3)
{
    long (*fn)(long,long,long,long,long,long) = (long (*)(long,long,long,long,long,long))n;
    return fn(a1,a2,a3,0,0,0);
}

static inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
    long (*fn)(long,long,long,long,long,long) = (long (*)(long,long,long,long,long,long))n;
    return fn(a1,a2,a3,a4,0,0);
}

static inline long __syscall5(long n, long a1, long a2, long a3, long a4,
                              long a5)
{
    long (*fn)(long,long,long,long,long,long) = (long (*)(long,long,long,long,long,long))n;
    return fn(a1,a2,a3,a4,a5,0);
}

static inline long __syscall6(long n, long a1, long a2, long a3, long a4,
                              long a5, long a6)
{
    long (*fn)(long,long,long,long,long,long) = (long (*)(long,long,long,long,long,long))n;
    return fn(a1,a2,a3,a4,a5,a6);
}

#endif

#define IPC_64 0
