#include <stdio.h>

// 枚举 成员是常量
enum game {LEFT = 1, RIGHT, UP, DOWN, QUIT = 9}; 

int main(void)
{
	printf("%d %d %d %d %d\n", LEFT, RIGHT, UP, DOWN, QUIT);

	return 0;
}

