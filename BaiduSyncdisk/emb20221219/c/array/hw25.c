/*
 读入两个字符串，比较长短，输出短的字符串及长度.
 */
#include <stdio.h>

#define N	16

int main(void)
{
	char str1[N] = {};
	char str2[N] = {};
	int len1, len2;

	printf("str1:");
	fgets(str1, N, stdin);
	printf("str2:");
	fgets(str2, N, stdin);

	// 包括终止字符的长度
	len1 = 0;
	while (str1[len1++])
		;
	len2 = 0;
	while (str2[len2++])
		;
	len1 > len2 ? puts(str2) : puts(str1);


	return 0;
}

