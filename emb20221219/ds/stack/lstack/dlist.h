#ifndef __DLIST_H__
#define __DLIST_H__

// ADT		双向环链
// 边长结构体
struct node_st {
	struct node_st *prev;
	struct node_st *next;
	char data[0]; // char data[1]
};

typedef struct {
	struct node_st head; 
	int size;
}dlisthead_t;

typedef int cmp_t(const void *data, const void *key);

typedef void (*pri_t)(const void *data);

// interface
extern int dlisthead_init(dlisthead_t **dl, int size);

extern int dlist_is_empty(const dlisthead_t *dl);

extern int dlist_insert_head(dlisthead_t *dl, const void *data);
extern int dlist_insert_tail(dlisthead_t *dl, const void *data);

extern void *dlist_search(const dlisthead_t *dl, const void *key, cmp_t *cmp);

extern int dlist_update(const dlisthead_t *dl, const void *key, cmp_t *cmp, const void *new_data);

extern int dlist_delete(dlisthead_t *dl, const void *key, cmp_t *cmp);

extern void dlist_traval(const dlisthead_t *dl, pri_t pri);

extern void dlist_destroy(dlisthead_t *dl);

// 获取首结点的数据
extern void *dlist_get_first_data(const dlisthead_t *dl);

// 摘除任意一个结点，并回填(参数)其数据
extern int dlist_fetch(dlisthead_t *dl, const void *key, cmp_t *cmp, void *data);

// 逆序
extern void dlist_reverse(dlisthead_t *dl);

#endif

