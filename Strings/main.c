#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>


int main(int argc, char *argv[]) {
	system("chcp 65001 > nul");
	
	char s[20] = "Hello"; // string length up to 19
	
	wchar_t  ch;
	wchar_t ws[20] = L"Привет";
	
	puts(s);
	
	printf("strlen(s): %d sizeof(s): %d\n", strlen(s), sizeof(s));
	printf("wcslen(ws): %d sizeof(ws): %d\n", wcslen(ws), sizeof(ws));
	
	char name[21] = "Sergey";
	//printf("Введите ваше имя: ");
	//gets(name);
	// Hello, Sergey!
	
	// char hello[100]; // static array
	// char hello[strlen(name)+8+1]; // VLA
	char* hello = malloc( (strlen(name)+8+1)*sizeof(char) ); // heap
	/*strcpy(hello, "Hello, ");
	strcat(hello, name);
	strcat(hello, "!");*/
	sprintf(hello, "Hello, %s!", name);
	
	puts(hello);
	

	const char* source = "Sergey,Andrey";
	
	int separation_position = -1;
	int strl = strlen(source);
	for(int i = 0; i < strl; i++)
		if (isspace(source[i]) || ispunct(source[i])) {
			separation_position = i;
			break;
		}
	
	char names[2][21];
	if (separation_position >= 0) {
		strncpy(names[0], source,separation_position);
		strcpy(names[1], &source[separation_position+1]);
		puts(names[0]);
		puts(names[1]);
	}
		
	
	
	
	
	
	
	
	free(hello);
	return 0;
}