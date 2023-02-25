/*
 随机数
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define N	20

/*
 定义个整型数组，有20个元素，值随机产生，求出数组的最大最小值
 */

int main(void)
{
	int arr[N] = {}; // 初始化为0
	int i;
	int max, min;

	// 提供种子 time(NULL)获取当前时间戳
	// srand(time(NULL));
	// getpid()获取调用进程进程号
	srand(getpid());

	for (i = 0; i < N; i++) {
		// 随机数产生
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
		printf("%d ", *(arr + i));
		printf("%d ", i[arr]);
	}
	printf("\n");

	// 最大最小值
	max = min = arr[0];
	for (i = 1; i < N; i++) {
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	printf("最大值:%d\n", max);
	printf("最小值:%d\n", min);

	// 验证数组名
	printf("arr:%p\n", arr);
	printf("arr+1:%p\n", arr+1);
	printf("*arr:%d\n", *arr);
	printf("*(arr+1):%d\n", *(arr + 1));
	printf("*arr+1:%d\n", *arr + 1);
	
	return 0;
}

