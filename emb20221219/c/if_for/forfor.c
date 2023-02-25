#include <stdio.h>
/*
统一100以内有多少个质数 
 */
int main(void)
{
	int i, j;
	int cnt = 0;

	for (i = 0; i <= 100; i++) {
		if (i <= 1)
			continue;
		if (i == 2) {
			cnt ++;
			continue;
		}
		// 判断i是否为质数
		for (j = 2; j < i; j++) {
			if (i % j == 0)	
				break;
		}
		if (i == j)
			cnt ++;
	}

	printf("100内有%d个质数\n", cnt);

	return 0;
}

