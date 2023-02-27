/*
 指针:存储地址的变量
 类型:取决于存储地址类型
 char * int * int[3] *
 void *万能指针，存储任意类型地址,但是不能做运算
 NULL 宏，空指针 零地址 (void *)0
 做运算:
 	取决于存储的地址类型
	char * sizeof(char)
	int * sizeof(int)
	long * sizeof(long)
 存储空间大小:
 	存地址，64地址，指针都是8bytes
 */
#include <stdio.h>

void show_arr(int p[], int n);
int main(void)
{
	int arr[3] = {12, 22, 32};
	// p指针变量 int *类型
	int *p = arr; // int *

	printf("*p:%d\n", *p);
	printf("p:%p\n", p);
	printf("p + 1:%p\n", p + 1);
	p++; // &arr[1]
	printf("*p:%d\n", *p);

	show_arr(arr, 3);

	return 0;
}

// 数组作为参数传递
// void show_arr(int p[n]) // p也不是数组，是int *指针，表示以p为起始地址有n成员属于你
// void show_arr(int *p, int n)
void show_arr(int p[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		// printf("%d ", *(p + i));
		printf("%d ", p[i]);
	}
	printf("\n");
}

