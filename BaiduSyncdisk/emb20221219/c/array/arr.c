#include <stdio.h>

/*
 数组:相同类型元素的集合
 定义:
 	确定类型
	数组名
	成员个数
 */
int main(void)
{
	// 定义
	int arr[10];
	// 初始化
	int arr2[3] = {1, 2, 9};
	int i;

	// 元素访问--->下标值访问，从0开始
	// 下标0~9
	for (i = 0; i < 10; i++) {
		arr[i] = i + 1;
	}

	// 遍历
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

