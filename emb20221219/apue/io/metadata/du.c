#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE	128

/*
 统计给定路径对应的文件所占磁盘空间大小(k)
 stat(2)--->st_blocks(512bytes) / 2 --->k
 path--->非目录 return st_blocks / 2;
     --->目录 sum = 目录本身大小
	     解析目录 累加所有路径st_blocks
 */
int mydu(const char *path);

int main(int argc, char *argv[])
{
	if (argc > 1)
		printf("%dK %s\n", mydu(argv[1]), argv[1]);

	return 0;
}

// path路径对应的文件占多少st_blocks
static int __blocks(const char *path)
{
	struct stat res;
	int sum = 0;
	DIR *dp;
	struct dirent *entry;
	char buf[BUFSIZE] = {};
	
	if (-1 == stat(path, &res)) {
		perror("stat()");
		return -1;
	}
	// DIR?
	if (!S_ISDIR(res.st_mode)) {
		return res.st_blocks;
	}
	// 解析目录
	sum = res.st_blocks; // 目录本身

	// 累加目录下所有文件的总大小
	dp = opendir(path);
	if (NULL == dp) {
		perror("opendir()");
		return -1;
	}

	while (1) {
		entry = readdir(dp);
		if (NULL == entry) {
			if (errno) {
				perror("readdir()");
				return -1;
			}
			break;
		}
		if (strcmp(entry->d_name, ".") == 0 || \
				strcmp(entry->d_name, "..") == 0)
			continue;

		// path--->"/etc"
		// entry->d_name---->"passwd"
		// "/etc/passwd"
		memset(buf, '\0', BUFSIZE);
		strncpy(buf, path, BUFSIZE);
		strncat(buf, "/", BUFSIZE);
		strncat(buf, entry->d_name, BUFSIZE);
		sum += __blocks(buf);
	}

	closedir(dp);
	return sum;
}

int mydu(const char *path)
{
	return __blocks(path) / 2;	
}






