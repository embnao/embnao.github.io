#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define OPTSTRING	"-lah"

int main(int argc, char *argv[])
{
	struct stat res;
	DIR *dp;
	struct dirent *entry;
	int c;

	// 解析命令行选项
	while (1) {
		c = getopt(argc, argv, OPTSTRING);			
		if (-1 == c)
			break; // 所有选项解析完成
		switch (c) {
			case 'a':
				printf("请调用选项-a你要实现的功能\n");
				break;
			case 'h':
				printf("请调用选项-h你要实现的功能\n");
				break;
			case 'l':
				printf("请调用选项-l你要实现的功能\n");
				break;
			case '?':
				printf("不认识\n");
				break;
			case 1:
				printf("识别到了非选项参数:%s\n", argv[optind-1]);
			default:
				break;
		}
	}

	if (argc < 2)
		return 1;

	// 判断是否为目录
	if (-1 == stat(argv[1], &res)) {
		perror("stat()");
		return 1;
	}
	if (!S_ISDIR(res.st_mode))
		return 1;

	// 解析
	dp = opendir(argv[1]);
	if (NULL == dp) {
		perror("opendir()");
		return 1;
	}

	while (1) {
		entry = readdir(dp);
		if (NULL == entry) {
			if (errno) {
				// 出错了
				perror("readdir()");
				goto ERROR;
			}
			// 读完了
			break;
		}
		printf("%s ", entry->d_name);
	}
	printf("\n");

	closedir(dp);

	return 0;
ERROR:
	closedir(dp);
	return 1;
}

