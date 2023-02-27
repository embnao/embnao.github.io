/*
	100~300共201个整型数,如果判断一个数是否为质数需要1s钟，那么
    现要求201数筛选是否为质数共1s（多线程并发）	
	是质数则打印输出

	线程创建pthread_create(3)
	线程终止pthread_exit(3)
	线程收尸pthread_join(3)
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define START	100
#define END		300
#define N		((END) - (START) + 1)

static int is_primer(int n)
{
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

static void *thr_job(void *s)
{
	sleep(1);
	int n = (int)s;	

	if (is_primer(n))
		printf("%d is a primer\n", n);

	pthread_exit(0);
}

int main(void)
{
	pthread_t tids[N] = {};
	int i, j;
	int err;

	for (i = START, j = 0; i <= END; i++, j++) {
		err = pthread_create(tids + j, NULL, thr_job, (void *)i);
		if (err) {
			fprintf(stderr, "pthread_create():%s\n", strerror(err));
			exit(1);
		}
	}

	// 收尸
	for (i = 0; i < N; i++)
		pthread_join(tids[i], NULL);
	

	exit(0);
}



