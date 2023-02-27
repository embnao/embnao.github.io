#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int (*cmp_t)(const void *, const void *);

void myqsort(void *arr, int nmemb, int size, cmp_t cmp);

static int cmp_int(const void *d1, const void *d2)
{
	int *data1 = (int *)d1;
	int *data2 = (int *)d2;

	return *data2 - *data1;
}

int main(void)
{
	int arr[] = {3,1,2,6,9,8,7,4,5,3};	

	qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), cmp_int);

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

/*
 交换
 */ 
void swap2num(void *data1, void *data2, int size)
{
	void *tmp = malloc(size);

	memcpy(tmp, data1, size);
	memcpy(data1, data2, size);
	memcpy(data2, tmp, size);

	free(tmp);
}

/*
 确定标兵在数组中位置
 */
int partision(void *arr, int low, int high, int size, cmp_t cmp)
{
	int k;
	char *a;

	// 选择标兵，并记录标兵位置
	k = low;

	a = arr;
	while (low < high) {
		while (cmp(a + k * size, a + high * size) < 0 && low < high)	
			high--;
		// 大小关系不符合需要交换 或者 low == high
		if (low == high)
			break;
		swap2num(a + k * size, a + high * size, size);	
		k = high;
		while (cmp(a + k * size, a + low * size) > 0 && low < high)
			low ++;
		if (low == high)
			break;
		swap2num(a + k * size, a + low * size, size);
		k = low;
	}

	return low;
}

static void __qsort(void *arr, int low, int high, int size, cmp_t cmp)
{
	int pos;

	if (low >= high)
		return;

	pos = partision(arr, low, high, size, cmp);
	__qsort(arr, low, pos - 1, size, cmp);
	__qsort(arr, pos + 1, high, size, cmp);
}

void myqsort(void *arr, int nmemb, int size, cmp_t cmp)
{
	__qsort(arr, 0, nmemb - 1, size, cmp);
}


