#include <stdio.h>
#include <stdlib.h>

typedef char* String;
//typedef const char* CString;
typedef const String CString;

/*
	Реализовать bool parseInt(const char* s, int* pn)
	для перевода строки в число в десятичной системе счисления

*/


int main(int argc, char *argv[]) {
	system("chcp 65001 > nul");
	{
		char* s = "abc";
		const char* cs = "Sergey";
		char* names[] = { "Анна", "Алиса", "Арабелла"};
		
		char** strArray = names;
	}
	
	{
		String s = "abc";
		CString cs = "Sergey";
		String names[] = { "Анна", "Алиса", "Арабелла"};
		
		String* strArray = names;
	}
	{
		CString s = "123";
		int x = atoi(s);
		
		printf("%d\n", x);
	}
	
	return 0;
}