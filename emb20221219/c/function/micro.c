/*
 宏
 */
#include <stdio.h>

// 所有出现N的编译器在预处理阶段都会将其替换为5
#define N	5

#define START	100
#define END		300

/*
 宏定义:
 名字建议大写
 在同一行
 */

// 一年有多少s
#define SECYEAR	365 * 24 * 60 * 60UL

// 宏函数 : ()很重要, 变量要加() 表达式最后也要加()
#define SQUARE(x)	((x) * (x))

#define SUM(x)	((x) + (x))

// 练习：写一个宏实现求两个数的最大值
#define MAX(x, y)	(((x) > (y)) ? (x) : (y))

// 交换两个整型变量
#define SWAP(x, y)	do {int t; t = (x); (x) = (y); (y) = (t);} while(0)

int main(void)
{
	int i, j;

	for (i = START; i <= END; i++) {
		printf("i:%d\n", i);
	}

	printf("%d\n", SQUARE(5));
	printf("%d\n", SQUARE(5 + 1));
	printf("%d\n", SQUARE(SUM(2+3)));
	// ((2+3) + (2+3)) * ((2+3) + (2+3))
	printf("%d\n", SUM(SQUARE(5 + 1)));
	// ((5 + 1) * (5 + 1)) + ((5 + 1) * (5 + 1))

	printf("%d\n", SUM(5 + 1) * SUM(2 + 3));
	// (5 + 1) + (5 + 1) * (2 +3 ) +(2 + 3)

	i = 10;
	j = 20;

	if (i < j)
		SWAP(i, j);
	printf("i:%d, j:%d\n", i, j);

	printf("%d\n", __LINE__);
	printf("%s\n", __FUNCTION__);
	printf("%s\n", __TIME__);
	printf("%d\n", __STDC__);


	return 0;
}

