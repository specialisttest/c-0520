/*
	1. Определить константу PI через макрос
	2. Опрелить макрофункцию для нахождения длины окружности по радиусу
	3. Определить макрофункцию для нахождения круга по радиусу
	4. Перенести созданные макросы в отдельный заголовочный файл, оформив его правильно
	
*/


#define ARCH x64
#define OS win

#include <stdio.h>
#include <stdlib.h>

#include "A.h"
#include "B.h"
#include "My.h"


#define ENTRY_POINT
#define DEBUG

#define THE_END  {\
			printf("Press enter....");\
			getchar();\
			fflush(stdin);\
		}

// макрофункция		
#define X2(x) ((x)*(x))

//#define RUS

#define ERROR_LEVEL 2


ENTRY_POINT int main(int argc, char *argv[]) {
	
#if ERROR_LEVEL	== 0
	puts("Errors");
#elif ERROR_LEVEL == 1
	puts("Errors, Warnings");
#elif ERROR_LEVEL == 2
	puts("Errors, Warnings, Notices");
#else
	#line 25
	#error INVALID ERROR LEVEL (0, 2)
#endif

#ifdef RUS
	system("chcp 65001 > null");
	printf("Привет\n");
#endif
	
	test();
	super_test();
	int y = 5;
	int x = 8;
	
	int z = X2(y); // y*y
	printf("z = %d\n", z);
	
	z = X2(7);
	printf("z = %d\n", z);
	
	z = X2(x*2+1); // ((x*2+1)*(x*2+1))
	#undef X2
	
//	
#ifdef DEBUG
	if (z == 289)
		printf("Error. File %s Line %d Function %s\n", __FILE__, __LINE__, __func__);
#endif
	
	printf("z = %d\n", z);
	
	int r = 5;
	
	printf("Circle length for radius %d : %f\n", r, CLEN(r+r));
	printf("Circle square for radius %d : %f\n", r, CSQR(r+r));
	
	long double q = 2.5;
	
	printf("Result: %d\n", sizeof(ROUND(q)));
	printf("Result: %Lf\n", q); // not working
	
		
	THE_END
	
	return 0;
}