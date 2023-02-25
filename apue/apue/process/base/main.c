#include <stdio.h>
#include <setjmp.h>
#include <unistd.h>
#include <stdlib.h>

// 环境表
extern char **environ;

static jmp_buf env;

void test();
int main(int argc, char *argv[])
{
	int i;

	// 跳转点 ERROR
	printf("%d\n", setjmp(env));
#if 0
	// 环境变量
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
#endif
	printf("早上好!\n");
	sleep(1);

	test();


	printf("hello world\n");

	return 0;
}

void test() 
{
	longjmp(env, 100);

	printf("%s is called", __FUNCTION__);
	// 终止进程
	exit(0); // 库
	// _exit(0); // 系统调用
}




