/*
 多维数组
 */

#include <stdio.h>

int main(void)
{
	// 数组的成员是数组
	// 由三个数组组成，每个数组由4个int类型的整型变量构成
	int arr[3][4] = {
		{11, 12, 13, 14},
		{21, 22, 23, 24},
		{31, 32, 33, 34}
	};
	int i, j;

	// arr是二维数组首元素(第一个一维数组)的地址
	// 所以arr的类型 int[4] *
	// 所以arr + 1 ---> sizeof(int[4])-->sizeof(int) * 4
	printf("arr:%p\n", arr);
	printf("arr + 1:%p\n", arr + 1);
	// *arr第一个数组中首元素(int)的地址
	// *arr类型int *
	printf("*arr:%p\n", *arr);
	printf("*arr + 1:%p\n", *arr + 1);

	// 取到值--->做两次取值运算 ** [][] *[]
	// 遍历 两循环 
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			// printf("%d ", arr[i][j]);
			// printf("%d ", *(arr[i] + j));
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}

	return 0;
}

