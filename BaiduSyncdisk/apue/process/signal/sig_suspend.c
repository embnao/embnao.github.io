#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define N	10

#define MYSIG SIGRTMIN	

static void sig_handler(int s)
{
	write(1, "!", 1);
}

int main(void)
{
	int i, j;
	sigset_t set, oldset;

	// signal(SIGINT, sig_handler);
	signal(MYSIG, sig_handler);

	sigemptyset(&set);
	// sigaddset(&set, SIGINT);
	sigaddset(&set, MYSIG);

	sigprocmask(SIG_BLOCK, &set, &oldset);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			write(1, "*", 1);
			sleep(1);
		}
		write(1, "\n", 1);
		// 信号驱动程序的运行
		sigsuspend(&oldset);
		/*
		 临时修改调用进程信号屏蔽字
		 等待信号到来
		 恢复调用进程的信号屏蔽字
		 */
	}

	return 0;
}

