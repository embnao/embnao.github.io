/*
 A
 A B
 A B C
 A B C D
 A B C D E
行数用用户键入 
 
A B C D E ......Z A
 */
#include <stdio.h>

int main(void)
{
	int line;
	int i, j;

	printf("line:");
	scanf("%d", &line);

	for (i = 0; i < line; i++) {
		for (j = 0; j <= i; j++) {
			printf("%c ", 'A' + j % 26);	
		}
		printf("\n");
	}

	return 0;
}

