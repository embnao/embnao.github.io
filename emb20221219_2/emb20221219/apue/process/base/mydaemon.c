/*
 写一个程序每秒钟将当前的时间yy-mm-dd HH:MM:SS
 追加写入"/tmp/out",每次写入加'\n'
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

#define BUFSIZE 128

static int mydaemon(void);
int main(void)
{
	time_t tm;
	struct tm *tmp;
	char buf[BUFSIZE] = {};
	FILE *fp;

	// 提交日志
	// 构建连接 systerm logger
	openlog("mydaemon", LOG_PID, LOG_DAEMON); // 可省略，有默认值

	// 守护进程
	if (-1 == mydaemon())
		exit(1);

	fp = fopen("/out", "w");
	if (NULL == fp) {
		// perror("fopen()");	
		syslog(LOG_ERR, "fopen():%s", strerror(errno));
		exit(1);
	}

	while (1) {
		// 获取当前时间---》时间字符串写入文件
		time(&tm);
		tmp = localtime(&tm);
		// if error
		strftime(buf, BUFSIZE, "%Y-%m-%d %H:%M:%S\n", tmp);	
		fputs(buf, fp);
		// 缓存
		fflush(fp);
		sleep(1);
	}

	return 0;
}

// 守护进程
static int mydaemon(void)
{
	int fd;
	pid_t pid;

	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		return -1;
	}

	if (pid > 0)
		exit(1);
	// 只有子进程 ，非组长进程
	if (-1 == setsid()) {
		perror("setsid()");
		return -1;
	}
	// PID == PGID == SID NO TTY

	umask(0);
	chdir("/");

	fd = open("/dev/null", O_RDWR);
	if (-1 == fd) {
		perror("open()");
		return -1;
	}
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	if (fd > 2)
		close(fd);

	return 0;
}








