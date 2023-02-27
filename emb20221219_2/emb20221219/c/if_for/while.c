/*
 while循环
 while (循环条件) {
 	循环体;
 }
 */
#include <stdio.h>

int main(void)
{
	int n;
	int res = 0;

	n = 1238;

	while (n) {
		res = res * 10 + n % 10;
		n /= 10;	
	}

	printf("倒序数:%d\n", res);

	return 0;
}

