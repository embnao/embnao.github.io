/*
 字符数组
 	char str[N];
	用于存储字符串变量
	字符串:由零个或者是多个字符组成, '\0'作为终止字符
 */
#include <stdio.h>

#define N	6

int main(void)
{
	// 存字符的数组
	char str1[N] = {'a', 'b', 'c', 'd', 'e', 'f'};
	// 存字符串的数组
	char str2[N] = {'a', 'b', 'c', 'd', 'e'};
	char str3[N] = "abcde"; // 等效于16行
	// char str4[N] = "abcdef"; // 越界了
	char str5[] = "abcdef"; // 允许，数组成员个数为7
	int i;

	// 遍历str1
	for (i = 0; i < N; i++)
		printf("%c ", str1[i]);
	printf("\n");
	
	// 遍历str2
	puts(str2);

	// 读入字符串
	// gets(str2); 永远别用 
	// stdin标准输入文件 
	fgets(str2, N, stdin);
	puts(str2);


	return 0;
}

