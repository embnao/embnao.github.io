#include <stdio.h>

#include "tree.h"

#define N	9

static int int_cmp(const void *data1, const void *data2)
{
	const int *d1 = data1;
	const int *d2 = data2;

	return *d2 - *d1;
}

static void show_int(const void *data)
{
	const int *d = data;
	printf("%d ", *d);
}

int main(void)
{
	int arr[N] = {3, 2, 1, 6, 7, 9, 4, 5, 8};

	btree_t *mytree = NULL;

	btree_init(&mytree, sizeof(int));

	for (int i = 0; i < N; i++)
		btree_add(mytree, arr+i, int_cmp);
	btree_mid_traval(mytree, show_int);
	btree_destroy(mytree);

	return 0;
}

