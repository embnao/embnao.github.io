/*
 定义个整型二维数组，由3x4组成
 值随机产生，将每一个一维数组中的最大值放最后
 {
 	{1, 10, 3, 2},
 	{11, 25, 44, 4},
	{99, 23, 11, 88}
 }
 {
 	{1, 2, 3, 10},
 	{11, 25, 4, 44},
	{88, 23, 11, 99}
 }
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define M	3
#define N	4

int main(void)
{
	int arr[M][N] = {};
	int i, j;
	int max;
	int t;

	srand(getpid());

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			arr[i][j] = rand() % 100;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	// 最大值放最后
	for (i = 0; i < M; i++) {
		max = 0;
		for (j = 1; j < N; j++) {
			max = arr[i][max] > arr[i][j] ? max : j;
		}
		if (max != N - 1) {
			t = arr[i][max];
			arr[i][max] = arr[i][N-1];	
			arr[i][N-1] = t;
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}



