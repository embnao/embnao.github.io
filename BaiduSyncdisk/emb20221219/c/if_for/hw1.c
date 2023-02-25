#include <stdio.h>

/*
 读入1~10之间的整型，输出对应的英文
 */

int main(void)
{
	int n;

	do {
		printf("请输入1~10之间的数值:");
		scanf("%d", &n);
	} while (!(n >= 1 && n <= 10));

	switch (n) {
		case 1:
			printf("one\n");
			break;
		case 2:
			printf("two\n");
			break;
		case 3:
			printf("three\n");
			break;
		case 4:
			printf("four\n");
			break;
		case 5:
			printf("five\n");
			break;
		case 6:
			printf("six\n");
			break;
		case 7:
			printf("seven\n");
			break;
		case 8:
			printf("eight\n");
			break;
		case 9:
			printf("nine\n");
			break;
		case 10:
			printf("ten\n");
			break;
		default:
			break;
	}

	return 0;
}

