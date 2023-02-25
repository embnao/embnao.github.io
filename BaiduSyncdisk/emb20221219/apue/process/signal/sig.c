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
	// SIGINT--->Ctrl+c
	// 注册新的行为
	ret = signal(SIGINT, sig_handler);

	while (1) {
		write(1, "*", 1);	
		sleep(1);
		i++;
		if (i > 5 && i < 10)
			signal(SIGINT, SIG_IGN);
		else if (i > 10)
			// signal(SIGINT, ret);
			signal(SIGINT, SIG_DFL);
	}


	exit(0);
}

