/*
 指针(的)常量
 常量(的)指针
 */
#include <stdio.h>

int main(void)
{
	char str[] = "hello";
	char *const p = str; // 指针常量 p++就是错误的，p不能改
	const char *q = str; // 常量指针 *q不能改,但不影响数组本身
	char const *r = str; // 同上

	p++; // 错 p只读的
	*p = 'w'; //允许的
	q++; // 允许
	*q = 'm'; // *q只读的

	return 0;
}

