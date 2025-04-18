#include "pthread_impl.h"
#include "syscall.h"

static volatile int check_robust_result = -1;

int pthread_mutexattr_setrobust(pthread_mutexattr_t *a, int robust)
{
    if (robust) return EINVAL;
    return 0;
}
