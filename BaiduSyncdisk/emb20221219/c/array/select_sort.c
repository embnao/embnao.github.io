/*
   选择排序
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define N	5

int main(void)
{
	int arr[N] = {};	
	int k;
	int t;
	int i, j;

	// 赋值
	srand(getpid());
	for (i = 0; i < N; i++) {
		arr[i] = rand() % 100;	
		printf("%d ", *(arr + i));
	}
	printf("\n");

	// 排序 i是待排序的位置
	for (i = 0; i < N - 1; i++) {
		// 由于从小到大,所以k表示无序序列中最小值的下标
		k = i;
		for (j = i + 1; j < N; j++)	 {
			// j是无序序列中每一个元素的下标
			if (arr[k] > arr[j]) {
				k = j;
			}
		}
		// for循环结束 k就是无序序列的最小值下标
		if (k != i) {
			t = arr[k];
			arr[k] = arr[i];	
			arr[i] = t;
		}
	}
	

	for (i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

