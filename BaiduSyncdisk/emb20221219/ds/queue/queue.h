#ifndef __QUEUE_H__
#define __QUEUE_H__

// ADT
typedef struct {
	void *s; // 起始地址		
	int front; // 队头下标
	int tail; // 队尾下标
	int capacity; // 容量
	int size;
}queue_t;

extern int queue_init(queue_t **q, int capacity, int size);

extern int queue_is_empty(const queue_t *q);

extern int queue_is_full(const queue_t *q);

extern int queue_enq(queue_t *q, const void *data);

extern int queue_deq(queue_t *q, void *data);

extern void queue_destroy(queue_t *q);

#endif

