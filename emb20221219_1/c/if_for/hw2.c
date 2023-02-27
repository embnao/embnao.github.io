#include <stdio.h>

/*
 个位是6，能被3整除但是不能被5整除的三位数有多少个，分别是哪些
 */
int main(void)
{
	int i;
	int cnt = 0;

	for (i = 100; i < 1000; i++) {
		if (i % 10 == 6 && i % 3 == 0 && i % 5 != 0) {
			printf("%d\n", i);
			cnt ++;
		}
	}
	printf("总共%d个\n", cnt);

	return 0;
}

