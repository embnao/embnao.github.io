/*
 将argv[1]字符串倒序生成新的字符串返回 并输出
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int reverse_string(const char *ptr, char **ret);

int main(int argc, char *argv[])
{
	char *p = NULL;

	if (argc < 2)
		return 1;
	reverse_string(argv[1], &p);

	puts(p);
	free(p);
	p = NULL;

	return 0;
}


static int reverse_string(const char *ptr, char **ret)
{
	int i, j;

	*ret = malloc(strlen(ptr) + 1);	
	if (NULL == *ret)
		return -1;

	for (i = strlen(ptr) - 1, j = 0; i >= 0; i--, j++)
		(*ret)[j] = ptr[i];
	(*ret)[j] = '\0';

	return 0;
}

