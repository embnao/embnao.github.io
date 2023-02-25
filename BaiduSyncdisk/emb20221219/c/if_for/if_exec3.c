/*
 经典面试题:
 	读入一个整型变量，将这个整型变量的第3位置1输出
	再将这个数的第5位清0输出
 */

#include <stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	if (n <= 0) 
		printf("非正整数\n");
	else {
		printf("第3位置1:%d\n", n | 1 << 3);	
		printf("第5位清0:%d\n", n & ~(1 << 5));	
	}

	return 0;
}

