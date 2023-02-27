#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;

	// 获取进程id
	printf("[parent] pid:%d, ppid:%d, pgid:%d, sid:%d\n", \
			getpid(), getppid(), getpgrp(), getsid(0));

	// 创建新的子进程
	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		exit(1);
	}
	// 成功--->两个进程
	if (0 == pid) {
		// child
		printf("[child] pid:%d, ppid:%d, pgid:%d, sid:%d\n", \
				getpid(), getppid(), getpgid(0), getsid(0));
		exit(0);
	}

	printf("hello everybody\n");

	// 等待子进程终止
	wait(NULL);

	printf("子进程结束后要做的工作\n");

	return 0;
}

