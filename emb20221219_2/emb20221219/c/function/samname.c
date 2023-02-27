#include <stdio.h>

int n;

void test(void);
int main(void)
{
	int n;

	n = 100;

	test();

	return 0;
}

void test(void)
{
	printf("n:%d\n", n);
}

