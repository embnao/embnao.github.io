#include <stdlib.h>
#include <string.h>
#include "queue.h"

int queue_init(queue_t **q, int capacity, int size)
{
	*q = malloc(sizeof(queue_t));
	if (NULL == *q)
		return -1;
	(*q)->s = calloc(capacity + 1, size);
	if (NULL == (*q)->s) {
		free(*q);
		return -1;
	}
	(*q)->front = (*q)->tail = 0;
	(*q)->capacity = capacity + 1;
	(*q)->size = size;

	return 0;
}

int queue_is_empty(const queue_t *q)
{
	return q->front == q->tail;
}

int queue_is_full(const queue_t *q)
{
	return (q->tail + 1) % q->capacity == q->front;
}

int queue_enq(queue_t *q, const void *data)
{
	if (queue_is_full(q))
		return -1;
	memcpy((char *)q->s + q->tail * q->size, data, q->size);
	q->tail = (q->tail + 1) % q->capacity;

	return 0;
}

int queue_deq(queue_t *q, void *data)
{
	if (queue_is_empty(q))
		return -1;
	memcpy(data, (char *)q->s + q->front * q->size, q->size);
	memset((char *)q->s + q->front * q->size, '\0', q->size);
	q->front = (q->front + 1) % q->capacity;

	return 0;
}

void queue_destroy(queue_t *q)
{
	free(q->s);
	q->s = NULL;
	free(q);
	q = NULL;
}

