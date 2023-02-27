#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

static void *thr_handler(void *s)
{
	for (int i = 0; i < 10; i++) {
		write(1, "!", 1);
		sleep(1);
	}

	pthread_exit((void *)0);
}

int main(void)
{
	pthread_t tid;
	int i;
	int err;

	err = pthread_create(&tid, NULL, thr_handler, NULL);
	if (err) {
		fprintf(stderr, "pthread_create():%s\n", strerror(err));
		exit(1);
	}

	i = 0;
	while (1) {
		write(1, "*", 1);
		sleep(1);
		i++;
		if (i == 5)
			break;
	}

	// return 0;
	pthread_exit((void *)0);
}

