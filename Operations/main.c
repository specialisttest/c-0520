#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	system("chcp 65001 > nul");
	
	int a;
	
	int b = a = 101;
	
	a += 2; //a = a + 2;
	
	printf("a = %d\nb = %d\n", a, b);
	
	a = 10;
	
	//a = a + 1;
	//a += 1;
	b = a++ + ++a; // UB
	
	printf("a = %d\nb = %d\n", a, b);
	
	bool r = (1 > 2);
	//r = true;
	//r = false;
	int k = (10 >= 2);
	
	printf("(1 > 2) %d\n", r);
	
	bool b1 = true;
	bool b2 = false;
	
	r = b1 && b2;
	r = b1 || b2;
	r = !b1;
	r = b1 && !b2;
	
	a = 112;
	
	r = (a >= 0) && (a <= 100);
	
	printf("%d\n", r);
	
	int x = 5; // 0101
	int y = 7; // 0111
	
	int z = x & y; // 0101
	z = x | y; // 0111
	z = x ^ y; // 0010 XOR
	
	z = x ^ y ^ y; // z == x;
	
	printf("z = %d\n", z);
	printf("x = %d\ny = %d\n", x, y);
	
	/*z = x;
	x = y;
	y = z;*/
	
	x ^= y ^= x ^= y;
	
	printf("x = %d\ny = %d\n", x, y);
	
	x = 7; // 0111
	
	//z = x >> 2; // 0111 >> 2 == 0001
	z = x << 3; // 0111 << 3 == 0111000
	
	x = 7; // 0111
	
	z = (x >> 1) & 1;
	
	printf("z = %d\n", z);
	
	int nums[20];
	nums[0] = 10;
	
	int q = 5;
	int* pq = &q;
	
	printf("sizeof(int) = %d\n", sizeof(a + b));
	
	double e = 5.9;
	
	int j = (int)e;  // cast operator
	
	printf("j = %d\n", j);
	
	x = 5;
	z = y = x + 5, x++;
	
	printf("x = %d\ny = %d\nz = %d\n", x, y, z);
	
	x = 33;
	y = 5;
	
	printf("x = %d\ny = %d\n", x, y);
	
	char* str = (x > y) ? "x больше y" : "x не больше y";
	
	puts(str);
	
	return 0;
}