#include "lstack.h"

int lstack_init(lstack_t **ls, int size)
{
	return dlisthead_init(ls, size);
}

// 是否为空
int lstack_is_empty(const lstack_t *ls)
{
	return dlist_is_empty(ls);
}

// 入栈
int lstack_push(lstack_t *ls, const void *data)
{
	return dlist_insert_head(ls, data);
}

// 出栈
static int __always_cmp(const void *data, const void *key)
{
	return 0;
}

int lstack_pop(lstack_t *ls, void *data)
{
	return dlist_fetch(ls, (void*)0, __always_cmp, data);
}

void lstack_destroy(lstack_t *ls)
{
	dlist_destroy(ls);
}

