#include <stdio.h>
#include <stdlib.h>

/*
	1. Пользователь вводит своё имя
	2. Hello, Name! или Hello, Stranger!
	
	#include <string.h>
	strlen(char*)
	gets_s(char*, max_length)
	gets(char*)

*/

int main(int argc, char *argv[]) {
	system("chcp 65001 > nul");
	
	int a = 2;
	int b;
	
	// оператор - выражение
	3 * (b = a + 2);
	
	// блочный (составной) оператор
	{
		#define ABC 123
		const int x = 5;
		printf("x = %d\n", x);
	}
	
	double x = 2.5;
abc:	
	{
		printf("%d\n", ABC);
		x = 3.5;
		{
			printf("x = %f\n", x);
			unsigned char x = 5;
			printf("x = %d\n", x);	
		}
		printf("x = %f\n", x);
	}
	printf("x = %f\n", x);
	
	// goto abc; // лучше не использовать (в большенстве случаев)
	
	// пустой оператор
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	
	int n = -10;

	if ( n > 0 ) {
		puts("n > 0");
		puts("n больше нуля");
	}
	else 
		if (n > -100)
			puts("n in (-100, 0]");
		else {
			puts("n не больше нуля");
			puts("n <= 0");
		}
	
	n = -1;	
	/*if (n == 1) puts("один");
	if (n == 2) puts("два");
	if (n == 3) puts("три");*/
	
	#define j 2
	
	switch(-2*n) {
		case -1:
		case 1 : 
			puts("один");
			break;
		case 1*j : 
			puts("два");
			break;
		case 3 : 
			puts("три");
			break;
		default:
			puts("много");
			
	}

	
	
	
	
	
	
	
	
	
	
		
	
	
	
	return 0;
}