#include <stdio.h>

#define N	32

int main(void)
{
	char str[N] = {};
	int i, j;
	
	fgets(str, N, stdin);

	// 循环结束i是'\0'的下标值
	for (i = 0; str[i]; i++)	
		;
	// 读入的字符串去掉'\n'
	if (str[i-1] == '\n')
		str[--i] = '\0';

	for (j = 0, --i; j < i; j++, i--) {
		if (str[j] != str[i])
			break;
	}
	if (j >= i)
		printf("%s是一个对称字符串\n", str);
	else
		printf("%s不是一个对称字符串\n", str);

	return 0;
}

