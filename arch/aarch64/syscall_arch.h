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

#undef SYSCALL_STATIC
#define SYSCALL_STATIC 1

#define SYSCALL_FADVISE_6_ARG
