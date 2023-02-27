/*
 杨辉三角前10行
	1
	1  1
	1  2  1
	1  3  3  1
	1  4  6  4  1
	1  5  10 10 5 1
 */
#include <stdio.h>

#define N	10

int main(void)
{
	int arr[N][N] = {};
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (j == 0 || i == j) {
				arr[i][j] = 1;
			} else if (j < i){
				arr[i][j] = arr[i-1][j] + arr[i-1][j-1];	
			}
			if (j <= i)
				printf("%d ", arr[i][j]);
		}
		printf("\n");
	}


	return 0;
}

