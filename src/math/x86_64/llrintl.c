#include <math.h>

extern long long llrintl(long double x);
/* { */
/* 	long long r; */
/* 	__asm__ ("fistpll %0" : "=m"(r) : "t"(x) : "st"); */
/* 	return r; */
/* } */
