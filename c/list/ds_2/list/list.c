#include <stdlib.h>
#include "list.h"

int listhead_init(listhead_t **h, int size)
{
	*h = malloc(sizeof(listhead_t));
	if (NULL == *h)
		return -1;
	(*h)->head.data = NULL;
	(*h)->head.next = &(*h)->head; // 循环链表
	(*h)->size = size;

	return 0;
}

// new插入在prev和next之间
static void __insert(struct node_st *new, struct node_st *prev, struct node_st *next)
{
	prev->next = new;
	new->next = next;
}

int list_insert(listhead_t *h, const void *data, int way)
{
	struct node_st *new, *last;	

	new = malloc(sizeof(struct node_st));
	if (NULL == new)
		return -1;
	new->data = malloc(h->size);
	if (NULL == new->data) {
		free(new);
		return -1;
	}
	// copy数据
	memcpy(new->data, data, h->size);

	// 插入
	if (LIST_HEAD_INSERT == way)
		__insert(new, &h->head, h->head.next);
	else if (LIST_TAIL_INSERT == way) {
		for (last = h->head.next; last->next != &h->head; last = last->next)
			;
		__insert(new, last, &h->head);
	}

	return 0;
}

// 找与key匹配的前驱结点
static struct node_st *__find_prev(listhead_t *h, const void *key, cmp_t cmp)
{
	struct node_st *prev;

	for (prev = &h->head; prev->next != &h->head; prev = prev->next) {
		if (cmp(prev->next->data, key) == 0)
			return prev;
	}

	return NULL;
}


int list_delete(listhead_t *h, const void *key, cmp_t cmp)
{
	struct node_st *prev, *del;

	if (h->head.next == &h->head)
		return -1;

	prev = __find_prev(h, key, cmp);
	if (NULL == prev)
		return -1;
	del = prev->next;
	prev->next = del->next;
	del->next = NULL;

	free(del->data);
	free(del);

	return 0;
}

void list_traval(const listhead_t *h, pri_t pri)
{
	struct node_st *p;

	for (p = h->head.next; p != &h->head; p = p->next) {
		pri(p->data);
	}
}

static int __always_cmp(const void *data, const void *key)
{
	return 0;
}

void list_destroy(listhead_t *h)
{
	struct node_st *cur, *del;

	while (1) {
		if (-1 == list_delete(h, NULL, __always_cmp))
			break;
	}
	free(h);
	h = NULL;
}


