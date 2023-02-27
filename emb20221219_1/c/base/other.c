#include <stdio.h>

int main(void)
{
	char c;
	int n;

	printf("请输入一个字符:");
	scanf("%c", &c);

	c >= 'a' && c <= 'z' ? printf("小写字母\n") : printf("不是小写字母\n");
	// 读入一个整型变量，判断其奇偶性

	printf("请输入一个整数:");
	scanf("%d", &n);

	n % 2 ? printf("%d是一个奇数\n", n) : printf("%d 是一个偶数\n", n);

	return 0;
}

