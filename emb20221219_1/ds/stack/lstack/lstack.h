#ifndef __LSTACK_H__
#define __LSTACK_H__

#include "dlist.h"

typedef dlisthead_t lstack_t;

// 初始化
extern int lstack_init(lstack_t **ls, int size);

// 是否为空
extern int lstack_is_empty(const lstack_t *ls);

// 入栈
extern int lstack_push(lstack_t *ls, const void *data);

// 出栈
extern int lstack_pop(lstack_t *ls, void *data);

// 销毁
extern void lstack_destroy(lstack_t *ls);

#endif

