/* 
	读入一个字符，如果是大写字符就转换为小写输出
如果使小写字母，就转换为大写输出	
a
A
C
c
 */
#include <stdio.h>

int main(void)
{
	char c;

	printf("请输入一个字母:");
	scanf("%c", &c);

	if (c >= 'A' && c <= 'Z') {
		printf("%c\n", c + ('a' - 'A'));	
	} else if (c >= 'a' && c <= 'z') {
		printf("%c\n", c - ('a' - 'A'));	
	} else {
		printf("这不是字母\n");
	}

	return 0;
}

