/*
	定义一个整型数组，有20个元素值随机，将数组的最大值和最小值交换 
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define N	5

int main(void)
{
	int arr[N] = {};	
	int i;
	int max, min;
	int t;

	// 赋值
	srand(getpid());
	for (i = 0; i < N; i++) {
		arr[i] = rand() % 100;	
		printf("%d ", *(arr + i));
	}
	printf("\n");

	// 最大值最小值位置
	max = min = 0; // 下标值
	for (i = 1; i < N; i++) {
		if (arr[i] > arr[max])
			max = i;
		if (arr[i] < arr[min])
			min = i;
	}

	// 交换
	t = arr[max];
	arr[max] = arr[min];
	arr[min] = t;

	// 遍历
	for (i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

