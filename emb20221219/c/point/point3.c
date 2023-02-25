/*
 字符串
 */

#include <stdio.h>

int main(void)
{
	// 字符串变量
	char str[] = "hello";
	// 字符串常量
	char *p = "world";

	str[0] = 'w';

	p = str;
	*p = 'h';

	puts(p);

	return 0;
}	

