/*
 定义一个整型数组int arr[20];
 1)接口1:为给定的整形数组随机产生值
 2)接口2:打印数组
 3)接口3:返回数组中所有元素的最大值
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define N	20

void rand_arr(int *arr, int n);
void show_arr(int *arr, int n);
int max_arr(int *arr, int n);
int main(void)
{
	int arr[N] = {};
	int max;

	rand_arr(arr, N);
	show_arr(arr, N);
	max = max_arr(arr, N);

	printf("最大值:%d\n", max);

	return 0;
}

void rand_arr(int *arr, int n)
{
	int i;

	srand(getpid());
		
	for (i = 0; i < n; i++) {
		// arr[i] = rand() % 100;	
		// *(arr + i) = rand() % 100;	
		*arr = rand() % 100;
		arr ++;
	}
}

void show_arr(int *arr, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

}

int max_arr(int *arr, int n)
{
	int i;
	int max;
	
	max = arr[0];
	for (i = 1; i < n; i++) {
		if (max < arr[i])	
			max = arr[i];
	}

	return  max;
}





