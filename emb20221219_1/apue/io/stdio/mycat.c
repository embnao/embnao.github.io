#include <stdio.h>
#include <string.h>

#define BUFSIZE	1024

static int mycat(const char *path);
int main(int argc, char *argv[])
{
	if (argc < 2)
		return 1;

	mycat(argv[1]);

	return 0;
}

static int mycat(const char *path)
{
	FILE *fp;
	int c;
	char buf[BUFSIZE] = {};

	fp = fopen(path, "r");
	if (NULL == fp)
		return -1;

	// 文件流定位到文件的第11个字符
	fseek(fp, 10, SEEK_SET/*SEEK_CUR*/);
	printf("文件流的位置:%ld\n", ftell(fp));

	// io
#if 0	
	while (1) {
		c = fgetc(fp);
		if (EOF == c) {
			// 出错
			if (ferror(fp)) {
				goto ERROR;
			}
			// 读到文件的结束标志
			break;
		}
		fputc(c, stdout);
	}
#endif

	while (1) {
		// 按行读写
		memset(buf, '\0', BUFSIZE);
		if (NULL == fgets(buf, BUFSIZE, fp))
			break;
		fputs(buf, stdout);
	}

	fclose(fp);
	return 0;
ERROR:
	return -1;
}



