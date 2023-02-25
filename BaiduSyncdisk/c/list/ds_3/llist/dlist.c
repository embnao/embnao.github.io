#include <stdlib.h>
#include <string.h>
#include "dlist.h"

int dlisthead_init(dlisthead_t **dl, int size)
{
	*dl = malloc(sizeof(dlisthead_t));
	if (NULL == *dl)
		return -1;
	(*dl)->head.data = NULL;
	(*dl)->head.prev = (*dl)->head.next = &(*dl)->head;
	(*dl)->size = size;

	return 0;
}

int dlist_is_empty(const dlisthead_t *dl)
{
	return dl->head.prev == &dl->head && dl->head.next == &dl->head;
}

static void __insert(struct node_st *new, struct node_st *prev_node, struct node_st *next_node)
{
	new->prev = prev_node;
	new->next = next_node;
	prev_node->next = new;
	next_node->prev = new;
}

// 初始化新节点
static struct node_st *__alloc_node(const dlisthead_t *dl, const void *data)
{
	struct node_st *new = malloc(sizeof(*new));
	if (NULL == new)
		return NULL;
	new->data = malloc(dl->size);
	if (NULL == new->data) {
		free(new);
		return NULL;
	}
	memcpy(new->data, data, dl->size);
	new->prev = new->next = NULL;

	return new;
}

int dlist_insert_head(dlisthead_t *dl, const void *data)
{
	struct node_st *new;

	new = __alloc_node(dl, data);
	if (NULL == new)
		return -1;

	__insert(new, &dl->head, dl->head.next);
	return 0;
}

int dlist_insert_tail(dlisthead_t *dl, const void *data)
{
	struct node_st *new;

	new = __alloc_node(dl, data);
	if (NULL == new)
		return -1;

	__insert(new, dl->head.prev, &dl->head);
	return 0;
}

// 放回查找的结点
static struct node_st *__find_node(const dlisthead_t *dl, const void *key, cmp_t *cmp)
{
	struct node_st *p = NULL;

	for (p = dl->head.next; p != &dl->head; p = p->next) {
		if (!cmp(p->data, key))
			return p;
	}
	return NULL;
}

void *dlist_search(const dlisthead_t *dl, const void *key, cmp_t *cmp)
{
	struct node_st *f = __find_node(dl, key, cmp);	
	if (NULL == f)
		return NULL;
	return f->data;
}

int dlist_update(const dlisthead_t *dl, const void *key, cmp_t *cmp, const void *new_data)
{
	struct node_st *f = __find_node(dl, key, cmp);	
	if (NULL == f)
		return -1;
	memcpy(f->data, new_data, dl->size);

	return 0;
}

// 删除指定结点
static int __delete(struct node_st *del)
{
	del->prev->next = del->next;
	del->next->prev = del->prev;
	del->prev = del->next = NULL;

	free(del->data);
	del->data = NULL;
	free(del);
	del = NULL;

	return 0;
}

int dlist_delete(dlisthead_t *dl, const void *key, cmp_t *cmp)
{
	struct node_st *f = __find_node(dl, key, cmp);	
	if (NULL == f)
		return -1;
	__delete(f);

	return 0;
}

void dlist_traval(const dlisthead_t *dl, pri_t pri)
{
	struct node_st *p;

	for (p = dl->head.next; p != &dl->head; p = p->next) {
		pri(p->data);
	}
}

static int __always_cmp(const void *data, const void *key)
{
	return 0;
}

void dlist_destroy(dlisthead_t *dl)
{
	while (dlist_is_empty(dl)) {
		dlist_delete(dl, NULL, __always_cmp);
	}

	free(dl);
	dl = NULL;
}

