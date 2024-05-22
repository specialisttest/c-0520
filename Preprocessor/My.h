#ifndef _MY_H_
#define _MY_H_

#include <math.h>

#define PI 3.1415

#define CLEN(R) (2*PI*(R))
#define CSQR(R) (PI*pow((R), 2.))

#define ROUND(x) _Generic((x),\
	long double : roundl,\
	float:roundf,\
	default: round)\
(x)


#endif