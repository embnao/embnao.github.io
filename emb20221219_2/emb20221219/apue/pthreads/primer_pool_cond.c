#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define START	100
#define END		300
#define N		4

/*
 job == 0	任务还未发放
 job > 0 	任务还未被取走
 job == -1	所有任务发放完成
 */
static int job; // 临界区
static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER; // 初始化

static int is_primer(int n);
static void *thr_job(void *s);
int main(void)
{
	// 创建所有的任务线程---》发放任务---》等着收尸
	pthread_t tids[N] = {};
	int i, err;

	for (i = 0; i < N; i++) {
		if (err = pthread_create(tids + i, NULL, thr_job, NULL)) {
			fprintf(stderr, "pthread_create():%s\n", strerror(err));
			exit(1);
		}
	}

	for (i = START; i <= END; i++) {
		// 上一次发放的任务取走在分配新任务
		pthread_mutex_lock(&mut);
		while (job > 0) {
			pthread_cond_wait(&cond, &mut);
		}
		job = i;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mut);
	}

	// 
	pthread_mutex_lock(&mut);
	while (job > 0) {
		pthread_cond_wait(&cond, &mut);
	}
	job = -1;
	pthread_cond_broadcast(&cond);
	pthread_mutex_unlock(&mut);

	for (i = 0; i < N; i++) {
		pthread_join(tids[i], NULL);
	}

	pthread_mutex_destroy(&mut);
	pthread_cond_destroy(&cond);

	exit(0);
}

static void *thr_job(void *s)
{
	int n;
	// 循环抢任务，直到job == -1终止
	while (1) {
		pthread_mutex_lock(&mut);
		while (job == 0) {
			pthread_cond_wait(&cond, &mut);
		}
		if (job == -1) {
			pthread_mutex_unlock(&mut);
			pthread_exit(0);
		}
		n = job; // 竞争解除
		job = 0;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mut);

		if (is_primer(n)) {
			printf("%d is a primer\n", n);
		}
		sleep(1);
	}

}

static int is_primer(int n)
{
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return 0;
	return 1;
}


