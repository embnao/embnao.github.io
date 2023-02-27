#include <stdio.h>

#include "./op.h"

// 外部声明:不会分配存储空间
extern int test;

extern int test2;

extern int test3;

int main(void) 
{
	int m, n;

	m = 10, n = 20;

	printf("m + n = %d\n", add_2_num(m, n));
	printf("m / n = %d\n", div_2_num(m, n));
	// is_div(m);

	printf("test:%d\n", test);

	test2 = 1;
	printf("%d\n", test2);

	test3 = 200000;

	return 0;
}

