#ifndef __LIST_H__
#define __LIST_H__

/*
单链表 
数据类型:
	数据结点
	头结点
 */

enum {LIST_HEAD_INSERT, LIST_TAIL_INSERT};

// ADT
struct node_st {
	void *data; // 数据域
	struct node_st *next; // 后继指针
};

typedef struct {
	struct node_st head; // 包含后继指针
	int size; // 数据域字节大小
}listhead_t;

typedef int (*cmp_t)(const void *data, const void *key);
typedef void (*pri_t)(const void *data);

// 接口声明
// 初始化头结点
// extern listhead_t *listhead_init(int size);
extern int listhead_init(listhead_t **h, int size);

// 空
extern int listhead_is_empty(const listhead_t *h);

// 增 删 改 查 遍历
extern int list_insert(listhead_t *h, const void *data, int way);

extern int list_delete(listhead_t *h, const void *key, cmp_t cmp);

extern int list_update(const listhead_t *h, const void *key, cmp_t cmp, const void *new_data);

extern void *list_search(const listhead_t *h, const void *key, cmp_t cmp);

extern void list_traval(const listhead_t *h, pri_t pri);

// 销毁
extern void list_destroy(listhead_t *h);

// 逆序
extern int list_reverse(listhead_t *h);

// 逆序产生新的链表返回
extern listhead_t *list_newlist_reverse(const listhead_t *h);

#endif

