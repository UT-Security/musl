#ifndef SYSCALL_STATIC

#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

#define __asm_syscall(...) do { \
	__asm__ __volatile__ ( "svc 0" \
	: "=r"(x0) : __VA_ARGS__ : "memory", "cc"); \
	return x0; \
	} while (0)

static inline long __syscall0(long n)
{
	register long x8 __asm__("x8") = n;
	register long x0 __asm__("x0");
	__asm_syscall("r"(x8));
}

static inline long __syscall1(long n, long a)
{
	register long x8 __asm__("x8") = n;
	register long x0 __asm__("x0") = a;
	__asm_syscall("r"(x8), "0"(x0));
}

static inline long __syscall2(long n, long a, long b)
{
	register long x8 __asm__("x8") = n;
	register long x0 __asm__("x0") = a;
	register long x1 __asm__("x1") = b;
	__asm_syscall("r"(x8), "0"(x0), "r"(x1));
}

static inline long __syscall3(long n, long a, long b, long c)
{
	register long x8 __asm__("x8") = n;
	register long x0 __asm__("x0") = a;
	register long x1 __asm__("x1") = b;
	register long x2 __asm__("x2") = c;
	__asm_syscall("r"(x8), "0"(x0), "r"(x1), "r"(x2));
}

static inline long __syscall4(long n, long a, long b, long c, long d)
{
	register long x8 __asm__("x8") = n;
	register long x0 __asm__("x0") = a;
	register long x1 __asm__("x1") = b;
	register long x2 __asm__("x2") = c;
	register long x3 __asm__("x3") = d;
	__asm_syscall("r"(x8), "0"(x0), "r"(x1), "r"(x2), "r"(x3));
}

static inline long __syscall5(long n, long a, long b, long c, long d, long e)
{
	register long x8 __asm__("x8") = n;
	register long x0 __asm__("x0") = a;
	register long x1 __asm__("x1") = b;
	register long x2 __asm__("x2") = c;
	register long x3 __asm__("x3") = d;
	register long x4 __asm__("x4") = e;
	__asm_syscall("r"(x8), "0"(x0), "r"(x1), "r"(x2), "r"(x3), "r"(x4));
}

static inline long __syscall6(long n, long a, long b, long c, long d, long e, long f)
{
	register long x8 __asm__("x8") = n;
	register long x0 __asm__("x0") = a;
	register long x1 __asm__("x1") = b;
	register long x2 __asm__("x2") = c;
	register long x3 __asm__("x3") = d;
	register long x4 __asm__("x4") = e;
	register long x5 __asm__("x5") = f;
	__asm_syscall("r"(x8), "0"(x0), "r"(x1), "r"(x2), "r"(x3), "r"(x4), "r"(x5));
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
