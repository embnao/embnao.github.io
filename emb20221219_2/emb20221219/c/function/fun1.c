#include <stdio.h>

/*
函数:
	模块化编程---》减少代码重复，冗余
	定义
	声明
	调用
 */
// 声明 copy函数定义头
int is_even(int number);

int main(void)
{
	int n;
	int ret;

	printf("n:");
	scanf("%d", &n);

	/*
	 调用
	 var = 函数名(传递的数值);
	 */
	ret = is_even(n); // number = n
	if (ret) {
		printf("%d是一个偶数\n", n);
	} else {
		printf("%d是一个奇数\n", n);
	}

	return 0;
}

/*
 定义
 功能:判断给定的整型变量的奇偶性
 函数名:标识符 is_even isEven
 形参列表:已知条件 int number
 返回值:结果 偶数返回1 奇数返回0
 */
int is_even(int number)
{
	if (number % 2 == 0)
		return 1;
	else
		return 0;
}


