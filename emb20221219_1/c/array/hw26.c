/*
 读入两个字符串，比较长短, 短的接长的后边
 */
#include <stdio.h>

#define N	16

int main(void)
{
	char str1[N] = {};
	char str2[N] = {};
	int len1, len2;
	int i, j;

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

	if (len1 > len2) {
		for (i = len1 - 1, j = 0; str2[j] &&  i < N - 1; i++, j++) {
			str1[i] = str2[j];
		}
		str1[i] = 0; // '\0'
		puts(str1);
	} else {
		for (i = len2 - 1, j = 0; str1[j] &&  i < N - 1; i++, j++) {
			str2[i] = str1[j];
		}
		str2[i] = 0; // '\0'
		puts(str2);
	}

	return 0;
}

