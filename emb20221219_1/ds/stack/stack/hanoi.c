#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static int step = 0;

static void hanoi(stack_t *src, stack_t *dest, stack_t *mid, int n);
int main(void)
{
	stack_t *s1, *s2, *s3;
	int i;

	stack_init(&s1, 50, sizeof(int));
	stack_init(&s2, 50, sizeof(int));
	stack_init(&s3, 50, sizeof(int));

	for (i = 10; i > 0; i--) {
		stack_push(s1, &i);
	}

	hanoi(s1, s2, s3, 10);

	printf("最少需要%d步\n", step);

	while (!stack_is_empty(s2)) {
		stack_pop(s2, &i);
		printf("%d\n", i);
	}
		
	return 0;
}

static void move(stack_t *src, stack_t *dest)
{
	void *data = malloc(src->size);
	stack_pop(src, data);
	stack_push(dest, data);
	step ++;
	free(data);
	data = NULL;
}

// 将src栈上的n个圆盘挪到dest栈上，期间临时放到mid栈
static void hanoi(stack_t *src, stack_t *dest, stack_t *mid, int n)
{
	if (n <= 0)
		return;
	if (n == 1) {
		move(src, dest);
		return;
	}
	hanoi(src, mid, dest, n - 1);
	hanoi(src, dest, mid, 1);
	hanoi(mid, dest, src, n - 1);
}


