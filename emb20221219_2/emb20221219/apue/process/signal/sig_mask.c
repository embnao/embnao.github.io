#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define N	10

static void sig_handler(int s)
{
	write(1, "!", 1);
}

int main(void)
{
	int i, j;
	sigset_t set, oldset;

	signal(SIGINT, sig_handler);

	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	for (i = 0; i < N; i++) {
		// 输出一行期间不受2号信号干扰
		sigprocmask(SIG_BLOCK, &set, &oldset);
		for (j = 0; j < N; j++) {
			write(1, "*", 1);
			sleep(1);
		}
		write(1, "\n", 1);
		sigprocmask(SIG_SETMASK, &oldset, NULL);
	}

	return 0;
}

