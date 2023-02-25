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
	alarm(1);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[BUFSIZE] = {};

	if (argc < 2)
		return 1;

	signal(SIGALRM, sig_handler);
	alarm(1);

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


