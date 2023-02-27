/*
	定义一个能容纳20个元素的字符数组
从终端读入一行字符串, 将这个字符串倒序，并打印	
读入:fgets(3)
输出:puts(3)
 */
#include <stdio.h>

#define N	20

int main(void)
{
	char str[N];
	int i, j;
	char c;

	printf("请输入一个行字符串:");
	fgets(str, N, stdin);

	// i就是'\0'下标
	for (i = 0; str[i]; i++) 
		;
	for (j = i - 1, i = 0; i < j; i++, j--) {
		c = str[i];	
		str[i] = str[j];
		str[j] = c;
	}

	puts(str);

	return 0;
}

