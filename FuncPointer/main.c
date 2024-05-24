#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STEPS 1000000

typedef double (*MathFunction)(double);

double integral( MathFunction pFunc, //double (* pFunc)(double),
				 double a, double b){
	double w = (b - a) / STEPS;
	double summa = 0.0;
	for(int i=0; i < STEPS; i++) {
		double x = a + w * i + w / 2;
		double h = pFunc(x); //(*pFunc)(x) //sin(x);
		summa += w * h;
	}
	
	return summa;
}

double x2(double x)
{
	return x*x;
}

double log_sin(double x)
{
	return log(sin(x));
}


int main(int argc, char *argv[]) {
	
	// указатель на функцию
	// double (*)(double)
	
	size_t
	
	double (* pFunc)(double) = sin; // &sin
	MathFunction pFunc2 = cos; 
	
	double  r1 = integral(pFunc , 0.0, M_PI / 2);
	printf("integral sin (0, PI/2) = %.14f\n", r1);
	
	double  r2 = integral(x2 , 0.0, M_PI / 2);
	printf("integral x^2 (0, PI/2) = %.14f\n", r2);
	
	double  r3 = integral(log_sin , 0.0, M_PI / 2);
	printf("integral log(sin(x)) (0, PI/2) = %.14f\n", r3);
	
	return 0;
}