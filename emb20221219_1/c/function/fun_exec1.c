/*
统计有多少个水仙花数 
3位数，每一位的立方和等于这个数本身
 */
#include <stdio.h>

int is_flower(int num);

int main(void)
{
	int i;
	int cnt = 0;

	for (i = 100; i < 1000; i++) {
		if (is_flower(i)) {
			cnt ++;		
			printf("%d是一个水仙花数\n", i);
		}
	}

	return 0;
}

/*
 求立方
 */
int cube_n(int n)
{
	return  n * n * n;
}

/*
 一个整型数的每一位的立方和
 */
int cube_sum(int num)
{
	int sum = 0;

	while (num) {
		sum += cube_n(num % 10);
		num /= 10;
	}

	return sum;
}

/*
 判断是否是水仙花
 */
int is_flower(int num)
{
	return num == cube_sum(num);
}


