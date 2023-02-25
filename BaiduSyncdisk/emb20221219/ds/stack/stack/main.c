#include <stdio.h>
#include "stack.h"

int main(void)
{
	int i;
	int ret;

	stack_t *s;

	stack_init(&s, 8, sizeof(int));

	for (i = 1; i <= 10; i++) {
		stack_push(s, &i);
	}

	while ((ret = stack_is_empty(s)) == 0) {
		stack_pop(s, &i);
		printf("%d ", i);
	}
	printf("\n");

	stack_destroy(s);

	return 0;
}

