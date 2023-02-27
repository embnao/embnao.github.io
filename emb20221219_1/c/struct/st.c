#include <stdio.h>
#include <string.h>

#define NAMESIZE	32

/*
 结构体
 */ 
struct student {
	int no; // 学号
	char name[NAMESIZE];
	float score;
};

int main(void)
{
	// 变量定义
	struct student s;
	// 初始化
	struct student s2 = {2, "小白", 100};
	struct student *p;

	// 赋值
	s.no = 1;
	strcpy(s.name, "小黑");
	s.score = 9;

	p = &s;
	printf("%d %s %f\n", p->no, p->name, p->score);

	return 0;
}

