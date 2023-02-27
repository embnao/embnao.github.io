/*
	将argv[1]数字字符串转整型输出
  ./a.out 123
 123  
 ./a.out -583
 -583
 %d输出
 */
#include <stdio.h>

int myatoi(const char *ptr);
int main(int argc, char *argv[])
{
	if (argc < 2)
		return 1;

	printf("%d\n", myatoi(argv[1]));

	return 0;
}

static int is_digital(char c)
{
	return c >= '0' && c <= '9';
}

int myatoi(const char *ptr)
{
	int ret = 0;
	int positive = 1;

	while (*ptr) {
		if (*ptr == '-') {
			positive = -1;
			ptr ++;
		}
		if (!is_digital(*ptr))
			break;
		ret = ret * 10 + *ptr - '0';
		ptr ++;
	}

	return ret * positive;
}


