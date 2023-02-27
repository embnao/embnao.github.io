/*
读入一个整型变量，判断是否是一个质数 

// 终止循环的关键字break	continue终止本次循环，继续下一次循环
 
 */
#include <stdio.h>

int main(void)
{
	int n;
	int flag = 1;
	int i;

	do {
		printf("请输入一个正整数:");
		scanf("%d", &n);
	} while (n <= 0);

	if (n == 1)	
		printf("1非质数也非合数\n");
	else {
		for (i = 2; i < n; i++) {
			// 除了1和本身	
			if (n % i == 0) {
				flag = 0;	
				// 终止循环
				break;
			}
		}	
		if (flag) {
			printf("%d是一个质数\n", n);
		} else
			printf("%d不是一个质数\n", n);
	}
		

	return 0;
}

