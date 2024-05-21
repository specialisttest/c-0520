#define __STDC_LIB_EXT1__ 1
#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	1. Пользователь вводит своё имя
	2. Hello, Name! или Hello, Stranger!
	
	#include <string.h>
	strlen(char*)
	gets_s(char*, max_length)
	gets(char*)

*/


int main(int argc, char *argv[]) {
	char name[31];
	printf("Enter your name: ");
	//gets_s(name, 31);
	gets(name);
	
	/*
	//if (strlen(name) != 0)
	if (strlen(name))
		printf("Hello, %s!\n", name);
	else
		printf("Hello, Stranger!");
	*/
	
	if (strlen(name) == 0)
		strcpy(name, "Stranger");
		
	printf("Hello, %s!\n", name);
	
	return 0;
}