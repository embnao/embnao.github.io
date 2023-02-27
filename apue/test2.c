/* 
	创建5个任务线程，分别疯狂的向标准输出打印'a', 'b', 'c', 'd', 'e'
要求整个进程执行5s(alarm(5)), 输出的结果必须是abcdeabcdeabcdeabcde....

 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define N	5

/*
tid:0~N-1
cur_id == tid
tid==0--->'a'
tid==1 --->'b'
....
工作线程打印完后，cur_id = -1, main赋新值
 */
static int cur_id = -1;
static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static void *thr_job(void *s);
int main(void)
{
	pthread_t tids[N];
	int i, err;

	alarm(5);

	for (i = 0; i < N; i++) {
		err = pthread_create(tids+i, NULL, thr_job, (void *)i);
		if (err) {
			fprintf(stderr, "pthread_create():%s\n", strerror(err));
			exit(1);	
		}
	}

	for (i = 0; i < N; i = (i+1) % N)	{
		pthread_mutex_lock(&mut);	
		while (cur_id != -1) {
			pthread_cond_wait(&cond, &mut);
		}
		cur_id = i;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mut);
	}


	exit(0);
}

static void *thr_job(void *s)
{
	int myid = (int)s;

	while (1) {
		pthread_mutex_lock(&mut);	
		while (myid != cur_id) {
			pthread_cond_wait(&cond, &mut);
		}
		printf("%c", 'a' + myid);	
		fflush(NULL);
		cur_id = -1; // 打印完了 给main看
		pthread_cond_broadcast(&cond);	
		pthread_mutex_unlock(&mut);
	}	
}



