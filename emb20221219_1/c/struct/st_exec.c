/*
有20个学生，读入二十个学生的信息，
求出这个班的平均成绩
 */
#include <stdio.h>

#define N		5
#define SIZE	32

typedef struct student {
	int no;
	char name[SIZE];
	float score;
}stu_t;

void input_stu(stu_t *p, int n);
float averange(const stu_t *p, int n);

int main(void)
{
	stu_t arr[N] = {};

	input_stu(arr, N);
	printf("平均值:%f\n", averange(arr, N));

	return 0;
}

void input_stu(stu_t *p, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("请输入第%d个学生的信息(学号姓名成绩):", i + 1);
		scanf("%d%s%f", &(p+i)->no, p[i].name, &p[i].score);
	}

}

float averange(const stu_t *p, int n)
{
	float sum = 0.0;
	int i;

	for (i = 0; i < n; i++)
		sum += p[i].score;

	return sum / N;
}



