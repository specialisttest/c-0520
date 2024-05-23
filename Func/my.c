#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

#include "my.h"

void say_hello() {
	puts(HELLO_STR);
}

void say_hello_w_name(const char* name){
	printf("Hello, %s!\n", name);
}

void say_hello_w_name_age(const char* name, int age) {
	printf("Hello, %s - %d!\n", name, age);
	//return;
}

double my_average(int a, int b) {
	double r  = (a + b) / 2.;
	return r;
}

double bank_round(double x){
	if ( 
		(x - floor(x) == 0.5) &&
		( (long long)floor(fabs(x)) % 2 == 0 )
	 )
	 	return x >= 0 ? floor(x) : ceil(x);

	return round(x);
}
// n! = 1*2*3* ..(n-1)*n
// 0! = 1
// n! = (n-1)!*n
int factorial(int n) {
	if (n == 0) return 1;
	else return n*factorial(n-1);
}

double averagem(int m_size, int m[]){
	long summa = 0;
	for(int i=0; i < m_size; i++)
		summa += m[i];
		
	return (double)summa / m_size;
}

// Создатать ф-ю mediana с переменным
// количством параметров
int compare_int(const void* a, const void* b){
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;
	
	return arg1 - arg2;
}

double mediana(int n, ...){
	int arr[n]; // VLA
	va_list params;
	va_start(params, n);
	
	for(int i = 0; i < n; i++)
		arr[i] = va_arg(params, int);
	va_end(params);
	
	double median;
	qsort(arr, n, sizeof(int), compare_int);
	
	median = (n % 2 == 1) ? arr[n / 2] : (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
		
	return median;
	
}

double averagen(int n, ...) {
	long summa = 0;
	
	va_list params;
	va_start(params, n);
	for(int i =0; i < n; i++){
		int k = va_arg(params, int);
		summa += k;
	}
	va_end(params);
	
	return (double)summa / n;
	
}
