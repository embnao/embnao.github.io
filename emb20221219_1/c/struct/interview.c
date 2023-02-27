#include <stdio.h>

#define DPS	int *

typedef int *TPS;

int main(void)
{
	DPS a, b; // int *a, b;
	TPS m, n;

	printf("%ld %ld %ld %ld\n", sizeof(a), sizeof(b), sizeof(m), sizeof(n));

	return 0;
}

