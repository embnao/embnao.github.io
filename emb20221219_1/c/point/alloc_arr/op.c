#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr_insert_sort(int **p, int *nmemb, int n)
{
	int i;

	*p = realloc(*p, (*nmemb + 1) * sizeof(int));	

	// 找到n要插入的位置 大到小
	for (i = *nmemb - 1; i >= 0; i--) {
		if ((*p)[i] > n)
			break;
#if 0
		else {
			(*p)[i+1] = (*p)[i];
		}
#endif
	}
	// n要放i+1位置
	memmove(*p + i + 2, *p + i + 1, (*nmemb - (i + 1)) * sizeof(int));
	(*p)[i+1] = n;

	++*nmemb;
	return 0;
}

int *arr_insert(int *p, int *nmemb, int n)
{
	int *a = realloc(p, (*nmemb + 1) * sizeof(int));
	if (NULL == a)
		return NULL;
	a[*nmemb] = n;
	(*nmemb) ++;

	return a;
}

int arr_insert_v2(int **p, int *nmemb, int n)
{
	int *a;
	a = realloc(*p, (*nmemb + 1) * sizeof(int));
	if (NULL == a)
		return -1;
	a[*nmemb] = n;
	(*nmemb) ++;

	*p = a;

	return 0;

}

int arr_find(const int *p, int nmemb, int key);
int *arr_delete(int *p, int *nmemb, int key)
{
	int i;

	i = arr_find((const int *)p, *nmemb, key);	
	if (-1 == i)
		return p;
	// i + 1开始所有元素向前移动覆盖掉下标i元素
	for (; i < *nmemb - 1; i++)
		p[i] = p[i+1];
	(*nmemb) --;
	return realloc(p, *nmemb * sizeof(int));
}

int arr_find(const int *p, int nmemb, int key)
{
	int i;

	for (i = 0; i < nmemb; i++) {
		if (p[i] == key)
			return i;
	}

	return -1;
}

void arr_traval(const int *p, int nmemb)
{
	for (int i = 0; i < nmemb; i++)
		printf("%d ", p[i]);
	printf("\n");
}

void arr_destroy(int *p)
{
	free(p);
	p = NULL;
}

