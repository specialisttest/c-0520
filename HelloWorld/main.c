#define __STDC_LIB_EXT1__ 1
#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <tgmath.h>
#include <math.h>

#define ABC 123
//#define PI 3.1415


const double PI = 3.1415;
const int dimension = 3;

int main(int argc, char *argv[]) {
	
	//setlocale(LC_ALL, "Russian");
	
	//system("chcp 1251 > nul"); // specific for Windows
	system("chcp 65001 > nul");
	
	/* блочный комментарий */
	
	/*int x = 0b0101;
	
	char z = 'A';*/
	
//#undef ABC
	int a = ABC, b = 10;
	
	int q = 10;

	int x; // UB
	
	printf("\t \"x\" = %d\n", x);
	
	x = 10 + 2 * 2; // 14
	
	double y = 2.5e-3; // строчный комментарий
	
	printf("\t \"x\" = %d\n", x); // 14
	
	x = 5;
	
	printf("\t \"x\" = %d\n", x); // 5
	
	printf("y = %lf\n", y);
	
	/*int date, month, year;
	printf("Enter date (MM/DD/YYYY) : ");
	scanf("%d/%d/%d", &date, &month, &year);
	printf("Entered date: %d.%d.%d\n" , date, month, year);
	
	int hour = 0, min = 0;
	printf("Enter time (HH:MM) : ");
	scanf("%d:%d", &hour, &min);
	printf("Entered time: %d:%d\n" , hour, min);
	*/
	
	char name[16] = "no name";
	printf("Input your name: ");
	scanf_s("%s", name, 15); // since C11
	//scanf("%s", name);
	//gets(name);

	int age = 46;
	// Hello, Sergey - 46!
	printf("Hello, %s - 0x%x!\n", name, age);


	double inputData;
	printf("Введите вещественное число: ");
	scanf("%lf", &inputData);
	
	double result = sqrt(inputData);
	
	printf("Корен квадратный из числа %f равен %f\n", inputData, result);
	
	
	
	int R;
	
	printf("Address of R: %p\n", &R);
	
	printf("Введите радиус окружности: ");
	scanf("%d", &R);
	
	
	//double circleLength = 2 * M_PI * R;
	//printf("Circle length for radius %-5d is %20.10f\n", R, circleLength);
	
	
	printf("Hello World !\n");
	
	void* poin/*ter*/ = NULL;
	
	printf("Привет ужасный мир!\n");
	
	int j = 10;
	
	printf("sizeof int = %d\n", sizeof(int));
	printf("sizeof double = %d\n", sizeof(double));
	printf("sizeof long long int = %d\n", sizeof(long long int ));
	printf("sizeof long double = %d\n", sizeof(long double));
	
	double complex i = 0+1I;
	
	puts("Simple string");
	
	puts(name);
	
	return 0;
}
