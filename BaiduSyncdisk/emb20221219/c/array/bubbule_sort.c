#include <stdio.h>

#define N	9

/*
 冒泡排序
 */
int main(void)
{
	int arr[N] = {3, 7, 9, 10, 2, 1, 6, 8, 4};	
	int i, j;
	int t;

	// i 趟
	for (i = 0; i < N - 1; i++) {
		// 每一趟，无序序列范围j
		for (j = 0; j < N - i - 1; j++) {
			// 相邻元素
			if (arr[j] < arr[j+1]) {
				// 从大到小 交换
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
	}

	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");

	// 直接插入排序从小到大

	// 待插入元素的下标i
	for (i = 1; i < N; i++) {
		t = arr[i]; // 备份待插入元素
		// 向有序序列中插入
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > t)	{
				// 向后挪动
				arr[j+1] = arr[j];
			} else {
				break;
			}
		}
		arr[j+1] = t;
	}


	return 0;
}

