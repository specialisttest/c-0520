#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	for(int i = 0; i < 10; i++) {
		if (i == 3) continue;
		if (i == 8) break; //return
		printf("%d\n", i);
	}
	
	puts("");
	
	/*
		1  2  3  4   ... 10
		2  4  6  8   ... 20
		..
		10 20 30 40  ... 100	
		
	*/
	
	for(int i = 1; i <=10; i++) {
		for(int j = 1; j <= 10; j++) {
			if (j==5) goto end_for;//return;
			printf("%-4d", i * j);
		}
		printf("\n");
	}

end_for:	
	puts("\ncontinue main");
	
	for(int i=100; i >=0; i -=3)
		printf("%d\n", i);
		
	//for(;условие;)
	//while(условие)
	int x = 2000;
	while( x < 1000 ) {
		printf("%d\n", x);
		x *= 2; // x = x * 2;
	}
	
	x = 2;
	do {
		printf("%d\n", x);
	} while( (x *= 2) < 1000);
		
		
	
	
	// infinite interations
	// for(;;);
	
	return 0;
}