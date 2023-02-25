/*
			A
		 B	A 
	  C	 B  A 
   D  C  B  A 
E  D  C  B  A 

行键入
			A
		 B	A  B
	  C	 B  A  B  C
   D  C  B  A  B  C  D
E  D  C  B  A  B  C  D  E
 
 */
#include <stdio.h>

int main(void)
{
	int line;
	int i, j;

	printf("line:");
	scanf("%d", &line);

	for (i = 0; i < line; i++) {
		// 空格	
		for (j = 0; j < line - i - 1; j++)
			printf("  ");
		// 左字母
		for (j = 'A' + i; j > 'A'; j--)
			printf("%c ", j);
		// 右字母
		for (j = 'A'; j < 'A' + i + 1; j++) {
			printf("%c ", j);
		}
		printf("\n");
	}

	return 0;
}

