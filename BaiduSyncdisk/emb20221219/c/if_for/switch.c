/*
   读入一个学生的成绩，判断所属等级
   A	90~100
   B	80~89
   C	70~79
   D	60~69
   E	0~59
 */
#include <stdio.h>

int main(void)
{
	int score;

	printf("请输入你的成绩:");
	scanf("%d", &score);

	if (score < 0 || score > 100)
		printf("成绩无效\n");
	else {
		switch (score / 10) {
			case 10:
			case 9:
				printf("A\n");
				break;
			case 8:
				printf("B\n");
				break;
			case 7:
				printf("C\n");
				break;
			case 6:
				printf("D\n");
				break;
			default:
				printf("E\n");
				break;
		}
	}

	return 0;
}

