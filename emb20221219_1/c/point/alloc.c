/*
 动态开辟
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *alloc_memery(int n);
int main(void)
{
	int *arr = alloc_memery(10);

	for (int i = 0; i < 10; i++) {
		arr[i] = i + 1;
		printf("%d ", arr[i]);
	}
	printf("\n");

	// 再放5个元素 共15
	arr = realloc(arr, 15 * sizeof(int));

	for (int i = 10; i < 15; i++) {
		arr[i] = i + 1;
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
	arr = NULL; // free(NULL)什么都不会做, 重复free一段堆空间，会产生段错误

	return 0;
}

// 容纳n个整型变量的存储空间
int *alloc_memery(int n)
{
	int *p;

	p = (int *)malloc(n * sizeof(int)); // 未初始化
	// p = (int *)calloc(n, sizeof(int)); // 已经初始化
	if (NULL == p)
		printf("存储空间开辟失败\n");

	memset(p, 0, n * sizeof(int));
	
	return p;
}


