#include <stdio.h>
#include <stdlib.h>

#define REAL_PI 3.11415
	
	
	
int funcCount() {
	static int counter = 0;
	counter++;
	return counter;	
}


int globalZ = 10;

void incrementGlobal() {
	globalZ++;
}

int power(register int base, register int e) {
	register int result = 1;
	while(e-- > 0) result *= base;
	return result;
}

// restrict since C11
void update(int* restrict pa, int* __restrict pb, int val) {
	*pa += val;
	*pb += val;
}


int main(int argc, char *argv[]) {
	// PI = 4; // compile error
	printf("REAL_PI = %f\n", REAL_PI);
	
	const double PI = 3.1415; // readonly variable
	// PI = 4; // compile error
	double* ppi = &PI; // warn
	
	(*ppi) = 4.0;
	
	
	printf("PI = %f\n", PI);
	
	{
		auto int x = 0;
		printf("x = %d\n", x);
	}
	{
		register int x = 5;
		// int* px= &x; // compile error
		printf("register x = %d\n", x);
	}
	
	printf(" 3 ^ 4 = %d\n", power(3, 4));
	
	printf("globalZ  = %d\n", globalZ);
	incrementGlobal();
	printf("globalZ  = %d\n", globalZ);
	
	decrementGlobalZ();
	printGlobalZ();
	
	printf("main globalZ  = %d\n", globalZ);
	
	multi2GlobalZ();
	
	printf("main globalZ  = %d\n", globalZ);
	
	volatile int y = 5;
	
	_Atomic long counter = 0; // since C11
	
	
	int a = 10;
	int b = 20;
	update(&a, &b, 5);
	printf("a = %d\nb = %d\n", a, b);	
	
	printf("First  call funcCount(): %d\n", funcCount());
	printf("Second call funcCount(): %d\n", funcCount());
	printf("Third  call funcCount(): %d\n", funcCount());
	
	return 0;
}