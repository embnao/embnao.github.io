#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	char *cmd[] = {"ls", "-l", NULL};
	pid_t pid;

	// shell
	while (1) {
		printf("[xxx@xxx]$ ");	
		// 读用户输入的命令 cmd
		getline(); // "ls -l" -->切割 "ls" "-l" man 3 strsep
		pid = fork();
		// if error
		if (0 == pid) {
			// 执行读入的命令(进程)	
			// execl("/bin/ls", "ls", "-l", NULL);
			// execlp("test", "./test",  NULL);
			// execlp("ls", "ls",  NULL);
			execv("/bin/ls", cmd);
			perror("execl()");	
			exit(1);
		}
		wait(NULL);	
	}

	return 0;
}

