#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
 #include <sched.h>

static void sig_handler(int s)
{
	printf("the calling process pid:%d\n", getpid());
	write(1, "sig_handler", 11);;	
}

int main(void)
{
	pid_t pid;

	signal(SIGINT, sig_handler);

	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		exit(1);
	}
	if (0 == pid) {
		pause();
		write(1, "world", 5);
		exit(0);
	}

	write(1, "hello", 5);
	// sleep(1);
	// 出让调度器
	sched_yield(); // 子进程先pause运行起来，在kill
	kill(pid, SIGINT);
	wait(NULL);

	exit(0);
}

