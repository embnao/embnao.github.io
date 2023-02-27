#ifndef __STACK_H__
#define __STACK_H__

// ADT
typedef struct {
	void *top; // 栈顶指针
	void *base; // 栈底指针
	int capacity; // 容量
	int size; // 每个成员的字节大小
}stack_t;

extern int stack_init(stack_t **s, int capacity, int size);

extern int stack_is_empty(const stack_t *s);

extern int stack_is_full(const stack_t *s);

extern int stack_push(stack_t *s, const void *data);

extern int stack_pop(stack_t *s, void *data);

extern void stack_destroy(stack_t *s);

#endif

