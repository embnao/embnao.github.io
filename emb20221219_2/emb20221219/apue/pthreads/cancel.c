/* 
	创建5个任务线程，分别疯狂的向标准输出打印'a', 'b', 'c', 'd', 'e'
要求整个进程执行5s(alarm(5)), 输出的结果必须是abcdeabcdeabcdeabcde....

 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

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
static pthread_t tids[N];

static void *thr_job(void *s);

static void alrm_handler(int s)
{
	// 向所有的工作线程发出取消请求
	int i;

	for (i = 0; i < N; i++) {
		pthread_cond_broadcast(&cond);
		pthread_cancel(tids[i]);
	}
	for (i = 0; i < N; i++) {
		pthread_join(tids[i], NULL);	
	}
	pthread_mutex_destroy(&mut);
	pthread_cond_destroy(&cond);

	exit(0);
}

int main(void)
{
	int i, err;
	struct sigaction act, oldact;

	act.sa_handler = alrm_handler;
	act.sa_flags = 0;
	sigaction(SIGALRM, &act, &oldact);
	alarm(2);

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

static void thr_exit_handler(void *arg)
{
	printf("%s is called\n", __FUNCTION__);
}

static void *thr_job(void *s)
{
	int myid = (int)s;

	// 注册终止处理函数
	pthread_cleanup_push(thr_exit_handler, NULL);

	// 取消类型
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

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
	// 不执行，为了语句完整
	pthread_cleanup_pop(0);
}



