#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

typedef void (*sighandler_t)(int);
static void sig_handler(int s)
{
	for (int i = 0; i < 3; i++) {
		write(1, "!", 1);
		sleep(1);
	}
}

int main(void)
{
	sighandler_t ret; 
	int i = 0;
	struct sigaction act, oldact;

	// SIGINT--->Ctrl+c
	// 注册新的行为
	// ret = signal(SIGINT, sig_handler);
	act.sa_handler = sig_handler;// SIG_IGN/SIG_DEF/function
	// act.sa_mask
	act.sa_flags = 0;
	sigaction(SIGINT, &act, &oldact);

	while (1) {
		write(1, "*", 1);	
		sleep(1);
		i++;
		if (i > 5 && i < 10)
			signal(SIGINT, SIG_IGN);
		else if (i > 10) {
			// signal(SIGINT, ret);
			act.sa_handler = SIG_DFL;
			act.sa_flags = 0;
			sigaction(SIGINT, &act, NULL);
		}
	}


	exit(0);
}

