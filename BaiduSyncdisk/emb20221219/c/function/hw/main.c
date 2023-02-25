#include <stdio.h>
#include "hw.h"

int main(void)
{
	int n1, n2, n3;

	n1 = 100, n2 = 10, n3 = 999;
	printf("max:%d\n", max3num(n1, n2, n3));

	printf("res:%d\n", op2num(n1, n2, '/'));

	printf("sum:%d\n", factorial_n(5));

	return 0;
}

