#include <math.h>

extern double sqrt(double x);
/* { */
/* 	__asm__ ("sqrtsd %1, %0" : "=x"(x) : "x"(x)); */
/* 	return x; */
/* } */
