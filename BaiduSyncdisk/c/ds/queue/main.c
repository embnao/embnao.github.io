#include <unistd.h>
#include <stdio.h>
#include "queue.h"

int main(void)
{
	int i;
	int ret;

	queue_t *s;

	queue_init(&s, 8, sizeof(int));

	for (i = 1; i <= 10 && !queue_is_full(s); i++) {
		queue_enq(s, &i);
	}

	printf("******************************\n");

	while ((ret = queue_is_empty(s)) == 0) {
		queue_deq(s, &i);
		printf("%d\n", i);
		sleep(1);
	}
	printf("\n");

	queue_destroy(s);

	return 0;
}

