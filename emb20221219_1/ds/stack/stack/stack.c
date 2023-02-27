#include <stdlib.h>
#include <string.h>
#include "stack.h"

int stack_init(stack_t **s, int capacity, int size)
{
	*s = malloc(sizeof(stack_t));
	if (NULL == *s) {
		return -1;
	}
	(*s)->top = (*s)->base = calloc(capacity, size);
	if ((*s)->top == NULL) {
		free(*s);
		return -1;
	}
	(*s)->capacity = capacity;
	(*s)->size = size;

	return 0;
}

int stack_is_empty(const stack_t *s)
{
	return s->top == s->base;
}

int stack_is_full(const stack_t *s)
{
	return ((char *)s->top - (char *)s->base) / s->size == s->capacity;
}

int stack_push(stack_t *s, const void *data)
{
	if (stack_is_full(s))
		return -1;
	memcpy(s->top, data, s->size);
	s->top = (char *)s->top + s->size;

	return 0;
}

int stack_pop(stack_t *s, void *data)
{
	if (stack_is_empty(s))
		return -1;
	s->top = (char *)s->top - s->size;
	memcpy(data, s->top, s->size);
	memset(s->top, '\0', s->size);

	return 0;
}

void stack_destroy(stack_t *s)
{
	free(s->base);
	s->base = NULL;

	free(s);
	s = NULL;
}

