#include <stdlib.h>
#include <string.h>
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

int listhead_is_empty(const listhead_t *h)
{
	return h->head.next == &h->head;
}

int list_update(const listhead_t *h, const void *key, cmp_t cmp, const void *new_data)
{
	struct node_st *prev, *up;

	prev = __find_prev(h, key, cmp);
	if (NULL == prev)
		return -1;
	up = prev->next;
	memcpy(up->data, new_data, h->size);

	return 0;
}

int list_reverse(listhead_t *h)
{
	struct node_st *last; // 最终逆序后的最后一个数据结点	
	struct node_st *first;

	for (last = h->head.next; last->next != &h->head; ) {
		first = last->next; // 将first作为第一个数据结点
		last->next = first->next;
		first->next = NULL;
		__insert(first, &h->head, h->head.next);
	}

	return 0;
}

listhead_t *list_newlist_reverse(const listhead_t *h)
{
	listhead_t *newlist;
	struct node_st *p;

	listhead_init(&newlist, h->size);

	for (p = h->head.next; p != &h->head; p = p->next) {
		list_insert(newlist, p->data, LIST_HEAD_INSERT);
	}

	return newlist;
}




