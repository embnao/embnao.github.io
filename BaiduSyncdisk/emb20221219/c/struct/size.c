#include <stdio.h>

// 指定对齐规则
#pragma pack(4)

// 结构体默认对齐规则，相邻元素对齐，整体对齐
struct test {
	short s;
	char c;
	int i;
	char c2;
	long l;
};

// 限制对齐，单字节对齐
struct test2 {
	char c1;
	int i1;
	char c2;
	long l1;
	char c3;
	int i2;;
}__attribute__((packed));

int main(void)
{
	struct test t;

	printf("%p %p %p %p %p\n", &t.s, &t.c, &t.i, &t.c2, &t.l);

	printf("%ld\n", sizeof(t));

	printf("%ld\n", sizeof(struct test2));

	return 0;
}

