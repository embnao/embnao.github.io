/*
 100 ~ 300之间共201个数值
 假如判断一个整型数是否为质数需要1s钟，
 现要求201个数值判断是否为质数共需要1s。
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define LEFT	100
#define RIGHT	300

static int is_primer(int n);
int main(void)
{
	pid_t pid;
	int i;

	for (i = LEFT; i <= RIGHT; i++) {
		pid = fork();
		if (-1 == pid) {
			perror("fork()");
			exit(1);
		}
		if (0 == pid) {
			if (is_primer(i))	
				printf("[%d]%d is a primer\n", getpid(), i);
			exit(0);
		}
	}

	// 所有子进程收尸
	for (i = 0; i < RIGHT - LEFT + 1; i++)
		wait(NULL);

	return 0;
}

/*
	是否为质数 
 */
static int is_primer(int n)
{
	int i;

	sleep(1);
		
	for (i = 2; i <=  n / 2; i ++)
		if (n % i == 0)
			return 0;
	return 1;
}







