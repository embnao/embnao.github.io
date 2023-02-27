/*
man 2 alarm(2)周期性产生SIGALRM信号
现要求使用此信号，将argv[1]按照指定速率写到终端
流量控制的方式:
	1. 漏桶
	2. 令牌桶
		令牌: 积攒的--->信号
		速率
		上限

扩展作业：
	实现一个令牌桶库，最多支持1024个令牌桶

 */
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define BUFSIZE 32	
#define BURST	100
#define CPS		10

static int token;

static void sig_handler(int s)
{
	// 每秒钟将token++ 
	token++;
	if (token > BURST)
		token = BURST;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[BUFSIZE] = {};
	struct itimerval itv;

	if (argc < 2)
		return 1;

	// sigaction
	signal(SIGALRM, sig_handler);
	itv.it_interval.tv_sec = 0; // 当it_value倒计时为0时，要将it_interval的值赋值给it_value 
	itv.it_interval.tv_usec = 500000; // 0.5s
	itv.it_value.tv_sec = 1; // 倒计时
	itv.it_value.tv_usec = 500000; 
	setitimer(ITIMER_REAL, &itv, NULL);

	fp = fopen(argv[1], "r");
	// if error

	while (1) {
		while (!token)
			pause();
		token--;
		// io
		memset(buf, '\0', BUFSIZE);
		fgets(buf, CPS, fp);
		fputs(buf, stdout);
		fflush(NULL);
	}
	fclose(fp);

	return 0;
}

