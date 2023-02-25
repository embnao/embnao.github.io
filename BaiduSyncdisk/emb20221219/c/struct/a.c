#include <stdio.h>

int main(void)
{
	int a[][3] = {{1,2,3}, {}, {5,6,7}};
	int i, j;

	for (i = 0; i < 9; i++) {
		printf("%d ", *(*a + i));
	}
	printf("\n");

	return 0;
}
