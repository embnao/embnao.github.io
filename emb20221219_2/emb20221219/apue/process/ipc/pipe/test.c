#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define BUFSIZE	64

static int cp_file(int rfd, int wfd);
int main(int argc, char *argv[])
{
	int pfd[2] = {};
	int pfd2[2] = {};
	pid_t pid;
	char buf[BUFSIZE] = {};

	if (argc < 2)
		exit(1);
	if (-1 == pipe(pfd)) {
		perror("pipe()");
		exit(1);
	}
	if (-1 == pipe(pfd2)) {
		perror("pipe()");
		exit(1);
	}

	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		exit(1);
	}
	if (0 == pid) {
		int fd;

		close(pfd[1]);
		close(pfd2[0]);
		read(pfd[0], buf, BUFSIZE);
		close(pfd[0]);

		fd = open(buf, O_RDONLY);
		if (-1 == fd) {
			perror("open()");
			close(pfd[1]);
			exit(1);
		}

		cp_file(fd, pfd2[1]);
		close(pfd2[1]);
		close(fd);
		exit(0);
	}

	close(pfd[0]);
	close(pfd2[1]);
	write(pfd[1], argv[1], strlen(argv[1]) + 1);
	close(pfd[1]);
	cp_file(pfd2[0], 1);
	close(pfd2[0]);
	wait(NULL);

	return 0;
}

// 复制
static int cp_file(int rfd, int wfd)
{
	char buf[BUFSIZE] = {};
	int cnt;

	while (1) {
		memset(buf, '\0', BUFSIZE);
		cnt = read(rfd, buf, BUFSIZE);
		if (0 == cnt) {
			break; // eof
		}
		else if (-1 == cnt) {
			/*
			 阻塞的系统调用被信号打断的情况称为假错
			 */
			if (errno == EINTR)
				continue;
			perror("read()");
			return -1;
		}
		write(wfd, buf, cnt);	
		sleep(1);
	}

	return 0;
}






