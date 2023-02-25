#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	void *ptr = NULL;
	pid_t pid;

	ptr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED | \
			MAP_ANONYMOUS, -1, 0);

	pid = fork();
	if (-1 == pid) {
		perror("fork()");
		exit(1);
	}
	if (0 == pid) {
		memcpy(ptr, "embedded", 8);
		exit(0);	
	}
	wait(NULL);
	puts(ptr);

	munmap(ptr, 1024);

	return 0;
}

