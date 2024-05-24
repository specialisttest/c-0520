#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 1. Создать ф-ю swap с параметрами в виде 2-х указателей на int
// которая должна поменять местами значения по этим указалям
// 2.* Сделать аналогичную ф-ю swapU для работы с любыми

int y = 20; // global - data segment

void swap(int* pa, int* pb) {
	int c = *pa;
	*pa = *pb;
	*pb = c;
}

void swapU(void* pa, void* pb, size_t size) {
	int pc[size];
	//void* pc = malloc( size );
	memcpy(pc, pa, size);
	memcpy(pa, pb, size);
	memcpy(pb, pc, size);
	
	//free(pc);
}

int main(int argc, char *argv[]) {
	
	int x = 10; // local (auto) - stack;
	int* px = &x;
	int* py = &y;
	
	// void*
	int* pz = malloc( sizeof(int) ); // dynamic - heap
	
	*px = 12; // x = 12
	*pz = 14;
	
	printf("x  = %d\n", x);
	printf("*px(stack       ) = %d\n", *px);
	printf("px (stack       ) = %p\n", px);
	printf("py (data segment) = %p\n", py);
	printf("pz (heap)         = %p\n", pz);
	
	py = px;
	
	//x++;
	//(*px)++;
	(*py)++;
	printf("x  = %d\n", x); // 13
	
	const int* cp = px; // &x
	//cp = pz; // OK
	// (*cp)++; // compile error - const pointer
	printf("*cp  = %d\n", *cp); // 13
	x++;
	printf("*cp  = %d\n", *cp); // 14
	int* pp = cp;
	(*pp)++;
	printf("*cp  = %d\n", *cp); // 15
	
	double d = 2.5;
	double* pd = &d;
	
	//pd = px; // warning
	(*pd) = 1.0; //  dangerous - corrupt data
	x = 0x1232560D;
	px = &x; // int*
	unsigned char* pbyte = (unsigned int*)px;
	printf("unsigned char: %d\n", *pbyte); // safe - get first byte
	
	void* pv = px;
	pv = pd;
	pd = pv;
	printf("void*: %p\n", pv);
	pv++;
	printf("void*: %p\n", pv);
	printf("d = %f\n", d);
	
	printf("void* to double: %f\n", *(double*)pv);
	
	int nums[] = {10, 20, 30};
	int* pnums = nums; // pnums = &nums[0]
	for(int i=0; i < 3; i++)
		//printf("nums[%d] = %d\n", i, nums[i]);
		//printf("pnums[%d] = %d\n", i, pnums[i]);
		printf("pnums[%d] = %d\n", i, *(pnums+i) );  // int* pnums = 0x100; i = 5 pnums+i == 0x100 + 5 * sizeof(int)
	
	printf("*pnums = %d\n", *pnums); // nums[0];
	printf(" pnums = %p\n", pnums);  // &nums[0]
	pnums++;//pnums +=1; // pnums = &nums[1]
	
	printf("*pnums = %d\n", *pnums); // nums[1];
	printf(" pnums = %p\n", pnums);  // &nums[1]
	
	
	free(pz);
	// *pz // unsafe
	pz = NULL;
	
	{
		int a = 5, b = 7;
		printf("a = %d\nb = %d\n",a,b);
		swap(&a, &b);
		printf("a = %d\nb = %d\n",a,b);
	}
	{
		double a = 5.3, b = 7.4;
		printf("a = %.1f\nb = %.1f\n",a,b);
		swapU(&a, &b, sizeof(double));
		printf("a = %.1f\nb = %.1f\n",a,b);
	}
	
	
	
	return 0;
}