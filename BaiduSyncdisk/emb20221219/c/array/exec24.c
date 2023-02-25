#include <stdio.h>

#define N	16

int main(void)
{
	char str1[N] = {};
	char str2[N] = {};
	int i;
	int equal = 1;

	printf("str1:");
	fgets(str1, N, stdin);
	printf("str2:");
	fgets(str2, N, stdin);

	i = 0; 
	while (str1[i] || str2[i]) {
		if (str1[i] != str2[i]) {
			equal = 0;
			break;
		}
		i++;
	}

	equal ? printf("相等\n") : printf("不等\n");

	return 0;
}

