#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include "tbf.h"

// ADT
typedef struct {
	int token;
	int cps;
	int burst;
}tbf_t;

// 存储所有令牌桶
tbf_t *libs[TBFNR] = {};
/*
 注册信号
 周期性遍历令牌桶库，对应积攒令牌
 */
static void sig_handler(int s)
{
	int i;	

	for (i = 0; i < TBFNR; i++) {
		if (libs[i] != NULL) {
			libs[i]->token += libs[i]->cps;
			if (libs[i]->token >= libs[i]->burst)
				libs[i]->token = libs[i]->burst;
		}
	}
}

static void sig_moduler_load()
{
	struct sigaction act, oldact;
	struct itimerval itv;

	act.sa_handler = sig_handler;
	act.sa_flags = 0;
	sigaction(SIGALRM, &act, &oldact);

	itv.it_interval.tv_sec = 1;
	itv.it_interval.tv_usec = 0;
	itv.it_value.tv_sec = 1;
	itv.it_value.tv_usec = 0;
	setitimer(ITIMER_REAL, &itv, NULL);

}

static int get_free_pos()
{
	int i;

	for (i = 0; i < TBFNR; i++)
		if (libs[i] == NULL)
			return i;

	return -1;
}

int tbf_init(int cps, int burst)
{
	static int inited = 0;
	tbf_t *tbf;
	int pos;

	if (!inited) {
		sig_moduler_load();
		inited = 1;
	}

	tbf = malloc(sizeof(tbf_t));
	if (NULL == tbf)
		return -1;
	tbf->cps = cps;
	tbf->burst = burst;
	tbf->token = 0;

	// 挂到令牌桶库中
	pos = get_free_pos();
	if (-1 == pos) {
		free(tbf);
		tbf = NULL;
		return -ENOSPC;
	}
	libs[pos] = tbf;

	return pos;
}

int tbf_fetch_token(int td, int ntokens)
{
	int give;

	if (td < 0 || ntokens <= 0)
		return -EINVAL;
	while (libs[td]->token == 0)
		pause();
	if (ntokens > libs[td]->token)
		give = libs[td]->token;
	else
		give = ntokens;
	libs[td]->token -= give;

	return give;
}


