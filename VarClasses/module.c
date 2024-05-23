#include <stdio.h>

static int globalZ = 20;

void decrementGlobalZ()
{
	globalZ--;
}

void printGlobalZ()
{
	printf("globalZ (from module): %d\n", globalZ);
}