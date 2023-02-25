#include <stdio.h>

int main(void)
{
	int num = 100;
	static int s = 200;
	const char *p = "hello";

	printf("&num:%p, &s:%p\n", &num, &s);
	printf("p:%p\n", p);

	getchar();

	return 0;
}

