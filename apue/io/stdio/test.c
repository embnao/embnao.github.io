/*
 将argv[1]复制到argv[2]
 */
#include <stdio.h>
#include <string.h>

#define BUFSIZE 64

static int mycp(const char *src, const char *dest);
int main(int argc, char *argv[])
{
	if (argc < 3)
		return 1;

	mycp(argv[1], argv[2]);

	return 0;
}

// cp
static int mycp(const char *src, const char *dest)
{
	FILE *rfp, *wfp;
	char buf[BUFSIZE] = {};
	int cnt;

	rfp = fopen(src, "r");
	if (NULL == rfp)
		return -1;
	wfp = fopen(dest, "w");
	if (NULL == wfp) {
		fclose(rfp);
		return -1;
	}

	while (1) {
		memset(buf, 0, BUFSIZE);
#if 0
		if (NULL == fgets(buf, BUFSIZE, rfp))
			break;	
		fputs(buf, wfp);
#endif
		if ((cnt = fread(buf, 1, BUFSIZE, rfp)) == 0)
			break;
		fwrite(buf, 1, cnt, wfp);
	}

	fclose(rfp);
	fclose(wfp);
	return 0;
}


