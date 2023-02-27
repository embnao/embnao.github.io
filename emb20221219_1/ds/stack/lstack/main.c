#include <stdio.h>
#include "lstack.h"

int main(void)
{
	int i;
	int ret;

	lstack_t *s;

	lstack_init(&s, sizeof(int));

	for (i = 1; i <= 10; i++) {
		lstack_push(s, &i);
	}

	while ((ret = lstack_is_empty(s)) == 0) {
		lstack_pop(s, &i);
		printf("%d ", i);
	}
	printf("\n");

	lstack_destroy(s);

	return 0;
}

