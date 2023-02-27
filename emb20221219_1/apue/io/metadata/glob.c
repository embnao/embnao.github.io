#include <stdio.h>
#include <glob.h>

int main(int argc, char *argv[])
{
	glob_t res;

	if (0 != glob("/etc/*", 0, NULL, &res))
		return 1;
	if (0 != glob("/etc/.*", GLOB_APPEND, NULL, &res))
		return 1;
	for (int i = 0; i < res.gl_pathc; i++) {
		puts((res.gl_pathv)[i]);
	}

	globfree(&res);

	return 0;
}

