/*
扩展作业：
	实现一个令牌桶库，最多支持1024个令牌桶

 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "tbf.h"

#define BUFSIZE 32	
#define BURST	100
#define CPS		10

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[BUFSIZE] = {};
	int td;
	int n;

	if (argc < 2)
		return 1;

	fp = fopen(argv[1], "r");
	// if error

	td = tbf_init(CPS, BURST);
	if (td < 0) {
		fprintf(stderr, "tbf_init():%s\n", strerror(-td));
		exit(1);
	}

	while (1) {
		n = tbf_fetch_token(td, CPS);
		// io
		memset(buf, '\0', BUFSIZE);
		if (NULL == fgets(buf, n, fp))
			break;
		fputs(buf, stdout);
		fflush(NULL);
	}
	fclose(fp);

	return 0;
}


