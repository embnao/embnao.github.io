#include <stdio.h>

int main(void)
{
	// 强转
	int m, n;
	float f = 1.9, g = 2.1;
	m = 1, n = 2;

	/*
	 隐式转换
	 int + float--->(float)m + f
	 int = float
	 int = (int)
	 向上转型
	 short-->int---->long --->long long --->float ---->double
	 // signed 和 unsigned做运算，在当前os环境，按照无符号数运算
	 */
	// 面试题
	int num = -100;
	unsigned int i = 5;

	num > i ? printf("负数竟然大于正数\n") : printf("负数还是小的\n");

	return 0;
}

