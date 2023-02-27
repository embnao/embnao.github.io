#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFSIZE	32

int main(void)
{
	int pfd[2] = {};
	pid_t pid;
	char buf[BUFSIZE] = {};
	int cnt;

	if (-1 == pipe(pfd)) {
		perror("pipe()");
		exit(1);
	}
	
	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		exit(1);
	}
	if (0 == pid) {
		close(pfd[1]);
		while (1) {
			cnt = read(pfd[0], buf, BUFSIZE);
			if (-1 == cnt) {
				perror("read()");
				exit(1);
			}
			if (0 == cnt) {
				break;
			}
			break;
		}
		puts(buf);
		close(pfd[0]);
		exit(0);
	}

	close(pfd[0]);
	// write(pfd[1], "good afternoon", 14);
	sleep(1);
	close(pfd[1]);
	wait(NULL);
	
	exit(0);
}

