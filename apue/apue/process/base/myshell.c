#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define N	128

static int sep_string(char *ptr, const char *delim, char **argv, int argc);
int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	pid_t pid;
	char *arr[N] = {};

	// shell
	while (1) {
		printf("[xxx@xxx]$ ");	
		// 读用户输入的命令 cmd
		if (-1 == getline(&lineptr, &n, stdin))
			exit(1);
		// "ls -l" -->切割 "ls" "-l" man 3 strsep
		
		sep_string(lineptr, " \t\n", arr, N);

		pid = fork();
		// if error
		if (0 == pid) {
			// 执行读入的命令(进程)	
			execvp(arr[0], arr);
			perror("execl()");	
			exit(1);
		}
		wait(NULL);	
		memset(lineptr, '\0', n);
	}

	return 0;
}

static int sep_string(char *ptr, const char *delim, char **argv, int argc)
{
	int i = 0;
	char *token;

	while (i < argc - 1) {
		token = strsep(&ptr, delim);	
		if (token == NULL)
			break;
		if (strcmp(token, "") == 0)
			continue;
		argv[i++] = token;
	}	
	for (; i < argc; i++)
		argv[i] = NULL;
	return 0;
}



