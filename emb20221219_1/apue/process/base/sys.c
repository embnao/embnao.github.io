#include <stdio.h>
#include <stdlib.h>

static void exit_handler1(void);
static void exit_handler2(void);
int main(void)
{
	// 注册终止处理程序
	atexit(exit_handler1);
	atexit(exit_handler2);

	system("ls -l -a");

	return 0;
}

static void exit_handler1(void)
{
	printf("%s is called\n", __FUNCTION__);
}

static void exit_handler2(void)
{
	printf("%s is called\n", __FUNCTION__);
}


