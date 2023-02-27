#include <stdio.h>

int main(void)
{
	printf("hello world");

	// 强制刷新
	fflush(stdout);
	// fflush(NULL);

	while (1)
		;

	return 0;
}

