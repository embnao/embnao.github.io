
/*
读入一个整型数,求出这个数的倒序数
 */
#include <stdio.h>

int main(void)
{
	int n;
	int rev_n;

	do {
		printf("n:");	
		scanf("%d", &n);
	} while(n <= 0);

	rev_n = 0;
	for (; n; n /= 10) {
		rev_n = rev_n * 10 + n % 10;	
	}

	printf("结果为:%d\n", rev_n);

	return 0;
}

