#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc < 2)	
		return 1;

	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (-1 == fd) {
		perror("open()");
		return 1;
	}

	dup2(fd, 1); // 原子操作
	/*
	 close(1);
	 dup(fd);
	 */

	printf("hello world\n");

	close(fd);

	return 0;
}

