#include <stdio.h>
#include <string.h>
#include "seqlist.h"

#define NAMESIZE	32

enum {INSERT = 1, DELETE, SHOW, SEARCH, QUIT};

struct stu_st {
	char name[NAMESIZE];
	int age;
	float score;
};

static void show_stu(const void *data);
static int name_cmp(const void *data, const void *key);
int main(void)
{
	seqlist_t *mylist;	
	int select;
	struct stu_st stu;
	const char *name = "hello";

	// 初始化顺序表
	mylist = seqlist_init(sizeof(struct stu_st));

	// 用
	while (1) {
		printf("1.插入 2.删除 3.遍历 4.搜索 5.退出\n");
		scanf("%d", &select);
		getchar(); // 清键入的'\n'
		if (QUIT == select)
			break;
		switch (select) {
			case INSERT:
				printf("姓名:");	
				fgets(stu.name, NAMESIZE, stdin);
				(stu.name)[strlen(stu.name)-1] = '\0';
				printf("年龄:");
				scanf("%d", &stu.age);
				printf("成绩:");
				scanf("%f", &stu.score);
				seqlist_add(mylist, &stu);	
				break;
			case SHOW:
				seqlist_traval(mylist, show_stu);
				break;
			case DELETE:
				seqlist_delete(mylist, name, name_cmp);
				break;
			case SEARCH:
				break;
		}
	}

	seqlist_destroy(mylist);

	return 0;
}

// 打印学生结构函数
static void show_stu(const void *data)
{
	const struct stu_st *s = data;
	printf("%s %d %f\n", s->name, s->age, s->score);
}

// 比较函数
static int name_cmp(const void *data, const void *key)
{
	const struct stu_st *d = data;
	const char *k = key;

	return strcmp(d->name, k);
}







