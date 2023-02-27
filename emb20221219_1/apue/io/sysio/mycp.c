#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE	64

static int cp_file(int rfd, int wfd);
int main(int argc, char **argv)
{
	int fd1, fd2;

	if (argc < 3)
		return 1;

	fd1 = open(argv[1], O_RDONLY);
	if (-1 == fd1) {
		// fprintf(stderr, "open():%s\n", strerror(errno));
		perror("open()");
		return -1;
	}

	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (-1 == fd2) {
		fprintf(stderr, "open(): %s\n", strerror(errno));
		close(fd1);
		return -1;
	}

	cp_file(fd1, fd2);

	close(fd1);
	close(fd2);

	return 0;
}

// 复制
static int cp_file(int rfd, int wfd)
{
	char buf[BUFSIZE] = {};
	int cnt;

	// 设置文件偏移量
	printf("%ld\n", lseek(rfd, 10, SEEK_SET));

	while (1) {
		memset(buf, '\0', BUFSIZE);
		cnt = read(rfd, buf, BUFSIZE);
		if (0 == cnt) {
			break; // eof
		}
		else if (-1 == cnt) {
			fprintf(stderr, "read() failed\n");
			return -1;
		}
		write(wfd, buf, cnt);	
	}

	return 0;
}


