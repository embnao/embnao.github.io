#include <stdio.h>
#include <stdlib.h>

#include "op.h"

int main(void)
{
	int *arr = NULL;
	int n = 0;

	/*
	arr = calloc(3, sizeof(int));
	for (int i = 0; i < 3; i++)
		arr[i] = i + 1;
	n = 3;
	*/

#if 0
	arr = arr_insert(arr, &n, 100);
	arr = arr_insert(arr, &n, 12);
	arr = arr_insert(arr, &n, 2);
	arr_traval(arr, n);

	printf("删除\n");
	arr_delete(arr, &n, 12);
	arr_traval(arr, n);
	arr_delete(arr, &n, 12);
#endif
	
	arr_insert_sort(&arr, &n, 1);
	arr_insert_sort(&arr, &n, 3);
	arr_insert_sort(&arr, &n, 2);
	arr_insert_sort(&arr, &n, 7);

	arr_traval(arr, n);

	arr_destroy(arr);

	return 0;
}

