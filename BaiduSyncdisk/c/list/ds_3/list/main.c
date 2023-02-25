#include <stdio.h>
#include "list.h"

static void show_int(const void *data);
static int int_cmp(const void *data, const void *key);
int main(void)
{
	int i;
	listhead_t *mylist;

	listhead_init(&mylist, sizeof(int));

	for (i = 1; i <= 10; i++) {
		list_insert(mylist, &i, LIST_HEAD_INSERT);
	}

	list_traval(mylist, show_int);

	// 删除
	int delid = 5;
	list_delete(mylist, &delid, int_cmp);
	delid = 10;
	list_delete(mylist, &delid, int_cmp);
	delid = 1;
	list_delete(mylist, &delid, int_cmp);
	printf("删除后:\n");
	list_traval(mylist, show_int);

	list_destroy(mylist);

	return 0;
}

static void show_int(const void *data)
{
	const int *d = data;

	printf("%d\n", *d);
}

static int int_cmp(const void *data, const void *key) 
{
	const int *d = data;
	const int *k = key;

	return *d - *k;
}




