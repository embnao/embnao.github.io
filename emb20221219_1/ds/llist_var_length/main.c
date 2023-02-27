#include <stdio.h>
#include "dlist.h"

static void show_int(const void *data);
static int int_cmp(const void *data, const void *key);
int main(void)
{
	int i;
	dlisthead_t *mydlist;

	dlisthead_init(&mydlist, sizeof(int));

	for (i = 1; i <= 10; i++) {
		dlist_insert_head(mydlist, &i);
	}

	dlist_traval(mydlist, show_int);
	printf("逆序:\n");
	dlist_reverse(mydlist);
	dlist_traval(mydlist, show_int);

	// 删除
	int delid = 5;
	dlist_delete(mydlist, &delid, int_cmp);
	delid = 10;
	dlist_delete(mydlist, &delid, int_cmp);
	delid = 1;
	dlist_delete(mydlist, &delid, int_cmp);
	printf("删除后:\n");
	dlist_traval(mydlist, show_int);

	dlist_destroy(mydlist);

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




