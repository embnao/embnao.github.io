/*
 指针必要性
 	实现形参改变实参
 */
#include <stdio.h>

void swap_nums(int *p1, int *p2);
int main(void)
{
	int num1, num2;

	num1 = 10, num2 = 20;

	swap_nums(&num1, &num2);

	printf("num1:%d, num2:%d\n", num1, num2);

	return 0;
}

/*
 交换两个整型变量
 */
void swap_nums(int *p1, int *p2)
{
	int t;
	t = *p1; // num1
	*p1 = *p2; // num1 = num2;
	*p2 = t; // num2 = t;
}



