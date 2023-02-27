/*
 递归
 */
#include <stdio.h>

int sumn(int n);
int fib(int n);
int main(void)
{
	int i;

	printf("sumn(100):%d\n", sumn(100));

	for (i = 1; i <= 20; i++)
		printf("%d ", fib(i));
	printf("\n");

	return 0;
}

// 前n项和
int sumn(int n)
{
	// 终止条件
	if (n == 0)
		return 0;

	return n + sumn(n-1);
}

/*
   求斐波那契数列的第n项
   1 1 2 3 5 8 13 21 ....
 */
int fib(int n)
{
	if (n == 1 || n == 2)	
		return 1;
	else if (n < 1)
		return 0;
	return fib(n - 1) + fib(n - 2);
}


