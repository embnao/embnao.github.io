#include <stdio.h>

int main(void)
{
	int a, b;
	int c, d, e;

	a = 10;
	b = 5;

	c = a & b; // 同时为1结果为1
	d = a | b; // 只要有1位为1，结果为1
	e = a ^ b; // 相同为0， 不同为1

	printf("c:%d, d:%d, e:%d\n", c, d, e);

	c = ~a; // ~0--->1  ~1--->0
	printf("c:%d\n", c);
	c = a << 2; // 高位移出，低位补0
	printf("c = a << 2:%d\n", c);
	c = a >> 2; // 低位移出，高位正数补0， 负数补1
	printf("c = a >> 2:%d\n", c);

	/*
	 负数以补码存储
	 补码===> 反码+1
	 反码===> 原码按位取反
	 */

	b = a = 100;
	a += 10; // a = a + 10;

	return 0;
}

