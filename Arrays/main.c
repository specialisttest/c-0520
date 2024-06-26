#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compare_int(const void* a, const void* b){
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;
	
	return arg1 - arg2;
	/*if (arg1 > arg2) return 1;
	if (arg1 < arg2) return -1;
	return 0;*/
}


int main(int argc, char *argv[]) {
	#define ASIZE 4
	int nums[ASIZE] = {100, 200, 300};
	//int nums[ASIZE] = {}; // fill with zero
	//int nums[] = {100, 200, 300};
	
	printf("sizeof int[3]: %d\n", sizeof(nums));
	
	//nums[0] = 100;
	//nums[1] = 200;
	
	int* pNums = nums;
	
	(*pNums)++; // nums[0]++;
	
	for(int i = 0; i < ASIZE; i++)
		printf("nums[%d] : %-4d", i, nums[i]);
	puts("");
	
	/*printf("int[0]: %d\n", nums[0]);
	printf("int[1]: %d\n", nums[1]);
	printf("int[2]: %d\n", nums[2]); // garbage => UB*/
	
	//char str[10] = { 72, 101, 108, 108, 111, 0};
	//char str[10] = { 'H', 'e', 'l', 'l', 'o', 0};
	char str[10] = "Hello";
	
	for(int i = 0; i < strlen(str); i++)
		printf("%c", str[i]);
	
	puts(str);
	
	#define NSIZE 10
	int n[] = {10, 15, 7, 3, 21, 1000, 18, 30, 14, 17};
	for(int i = 0; i < NSIZE; i++)
		printf("%-5d", n[i]);
	puts("");
	
	// find value in unsorted array
	// O(n)
	int search = 21;
	int found_index = -1;
	for(int i = 0; i < NSIZE; i++)
		if (n[i] == search) {
			found_index = i;
			break;
		}
		
	if (found_index == -1)
		printf("Value %d not found in array\n", search);
	else
		printf("Value %d found in %d position\n", search, found_index);

	// summary array
	int summa = 0;
	for(int i=0; i < NSIZE; i++)
		summa += n[i]; // summa = summa + n[i];
	printf("Summa: %d\n", summa);
	
	// average
	double average = (double)summa / NSIZE;
	printf("Average: %f\n", average);
	
	// find minimum
	int min = n[0];
	for(int i=1; i < NSIZE; i++)
		if (n[i] < min) min = n[i];
		
	printf("Minimum: %d\n", min);
	
	// find maximum
	int max = n[0];
	for(int i=1; i < NSIZE; i++)
		if (n[i] > max) max = n[i];
		
	printf("Maximum: %d\n", max);
	
	/*
	// bubble sort
	for(int i = 0; i < NSIZE - 1; i++) {
		for(int j = i + 1; j < NSIZE; j++)
			if (n[j] < n[i]) {
				int x = n[i];
				n[i] = n[j];
				n[j] = x;
			}
	}*/
	
	qsort(n, NSIZE, sizeof(int), compare_int);
	
	for(int i = 0; i < NSIZE; i++)
		printf("%-5d", n[i]);
	puts("");
	
	// find median value
	// SORT !!!
	double mediana;
	qsort(n, NSIZE, sizeof(int), compare_int);
	if (NSIZE % 2 == 1)
		mediana = n[NSIZE / 2];
	else
		mediana = (n[NSIZE / 2 - 1] + n[NSIZE / 2]) / 2.0; 
	
	printf("Mediana: %2.f\n", mediana);
	
	
	// бинарный поиск (в отсортированном массиве)
	// O(log2(n))
	search = 10;
	found_index = -1;
	
	qsort(n, NSIZE, sizeof(int), compare_int);
	int begin = 0, end = NSIZE - 1;
	while ( end - begin > 1 ){
		int middle_index = (begin + end) / 2;
		int k = n[middle_index];
		if (k == search) {
			found_index = middle_index;
			break;
		}
		if (k > search)
			end = middle_index;
		else // k < search
			begin = middle_index;
			
		if (end - begin <= 1) {
			if (n[begin] == search) {
				found_index = begin;
				break;
			}
			if (n[end] == search) {
				found_index = end;
				break;
			}
		}
	}
	
	if (found_index == -1)
		printf("Value %d not found in array\n", search);
	else
		printf("Value %d found in %d position\n", search, found_index);
		
	// Написать программу, которая определяет, сколько различных чисел находится в массиве.
	#define SIZE 15
	int numbers[SIZE]  = {18, 15, 17, 3, 21, 1000, 18, 30, 15, 17, 1000, 21, 18, 34, 12};
	int counter = 0;
	for (int i = 0; i < SIZE; i++) {
		bool found = false;
		int k = numbers[i];
		for (int j = 0; j < i; j++)
			if ( k == numbers[j]) {
				found = true;
				break;
			}
		if (!found) counter++;
	}
	
	for(int i=0; i < SIZE; i++) printf("%-5d", numbers[i]);
	puts("");
	printf("Unique count: %d\n", counter);
	
		
	// VLA (since C11) - only local arrays
	/*printf("Enter array size for ints: ");
	const int arr_size;
	scanf("%d", &arr_size);
	
	int arr[arr_size]; // VLA
	
	printf("sizeof VLA: %d\n", sizeof(arr));
	memset(arr, 0, sizeof(arr)); // string.h
	
	for(int i = 0; i < arr_size; i++)
		printf("%-5d", arr[i]);
	puts("");*/
	
	// Многомерные массивы
	#define ROWS 2
	#define COLS 3
	int m[ROWS][COLS] = 
	{
		{1,2,3},
		{4,5,6}
	};
	
	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLS; j++)
			printf("%-3d", m[i][j]);
			
		puts("");
	}
	
	
	
	return 0;
}