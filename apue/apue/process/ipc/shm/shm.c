#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	int shmid;
	pid_t pid;
	void *ptr;

	shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | IPC_EXCL | 0600);
	if (-1 == shmid) {
		perror("shmget()");
		exit(1);
	}

	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		goto ERROR;
	}

	if (0 == pid) {
		ptr = shmat(shmid, NULL, 0);
		if ((void *)-1 == ptr) {
			perror("shmat()");
			exit(1);
		}
		strcpy(ptr, "good afternoon");
		shmdt(ptr);
		exit(0);
	}

	wait(NULL);
	// 将共享内存映射到进程的虚拟地址空间
	ptr = shmat(shmid, NULL, 0);
	puts(ptr);
	shmdt(ptr);

	shmctl(shmid, IPC_RMID, NULL);
	return 0;
ERROR:
	shmctl(shmid, IPC_RMID, NULL);
	exit(1);
}

