#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "my.h"

void test1(int a) {
	printf("Address a in test1: %p\n", &a);
	a++;
	printf("test1 a = %d\n", a); // 11
}
void test2(int* pa){
	printf("Address a in test2: %p\n", pa);
	(*pa)++;
	printf("test2 a = %d\n", *pa); // 11
}


int main(int argc, char *argv[]) {
	say_hello();
	say_hello();
	say_hello_w_name("Sergey"); // name = "Sergey"
	say_hello_w_name("Alex");   // name = "Alex"
	
	say_hello_w_name_age("Andrey", 50);
	
	double avg = my_average(10, 11);
	printf("avg = %lf\n", avg);
	
	printf("round %.1lf : %.1lf\n", 1.1, round(1.1));
	printf("round %.1lf : %.1lf\n", 1.9, round(1.9));
	printf("round %.1lf : %.1lf\n", 1.5, round(1.5));
	printf("round %.1lf : %.1lf\n", 2.5, round(2.5));
	
	printf("round %.1lf : %.1lf\n", -1.1, round(-1.1));
	printf("round %.1lf : %.1lf\n", -1.9, round(-1.9));
	printf("round %.1lf : %.1lf\n", -1.5, round(-1.5));
	printf("round %.1lf : %.1lf\n", -2.5, round(-2.5));
	
	printf("%f\n", floor(avg)); // floor(1.9) == 1.0
	printf("%f\n", ceil(avg));  // ceil(1.1) == 2.0
	
	double d = -1.5;
	printf("|d| = %f\n", fabs(d));
	
	printf("bank_round %.1lf : %.1lf\n", 0.3, bank_round(0.3));
	
	printf("bank_round %.1lf : %.1lf\n", 1.1, bank_round(1.1));
	printf("bank_round %.1lf : %.1lf\n", 1.9, bank_round(1.9));
	printf("bank_round %.1lf : %.1lf\n", 2.9, bank_round(2.9));
	printf("bank_round %.1lf : %.1lf\n", 1.5, bank_round(1.5));
	printf("bank_round %.1lf : %.1lf\n", 2.5, bank_round(2.5));
	printf("bank_round %.1lf : %.1lf\n", 0.5, bank_round(0.5));
	
	
	printf("bank_round %.1lf : %.1lf\n", -1.1, bank_round(-1.1));
	printf("bank_round %.1lf : %.1lf\n", -1.9, bank_round(-1.9));
	printf("bank_round %.1lf : %.1lf\n", -2.9, bank_round(-2.9));
	printf("bank_round %.1lf : %.1lf\n", -1.5, bank_round(-1.5));
	printf("bank_round %.1lf : %.1lf\n", -2.5, bank_round(-2.5));	
	printf("bank_round %.1lf : %.1lf\n", -0.5, bank_round(-0.5));

	{
		int a = 10;
		printf("Address a in main1: %p\n", &a);
		test1( a ); // by value (copy)
		printf("main1 a = %d\n", a ); // 10
	}
	{
		int a = 10;
		printf("Address a in main1: %p\n", &a);
		test2( &a ); // by ref
		printf("main2 a = %d\n", a ); // 11
	}
	
	printf("6! = %d\n", factorial(6));
	
	int m[] = {15, 18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12};
	printf("averagem(15, 18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12) = %.2f\n",
		averagem(sizeof(m) / sizeof(int), m));
	
	printf("averagen(16, 15, 18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12) = %.2f\n",
		averagen(16, 15, 18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12));

	printf("mediana(16, 15, 18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12) = %.2f\n",
		mediana(16, 15, 18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12));
		
	return 0;
}


