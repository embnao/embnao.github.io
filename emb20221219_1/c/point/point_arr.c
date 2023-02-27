#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// int main(int argc, char **argv)
int main(int argc, char *argv[])
{
	char *str[10] = {"羊肉汤", "盒饭", "麻辣烫", "米线", "西红柿鸡蛋盖饭", "烤肉拌饭", "kfc", "火锅", "烤肉", "pizza"};
	char **p = str;

	srand(getpid());
	printf("今天中午吃:%s\n", str[rand() % 10]);

	for (int i = 0; i < argc; i++) {
		puts(argv[i]);
	}

	return 0;
}

