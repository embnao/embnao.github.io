#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#define NAMESIZE	32

struct stu_st {
	char name[NAMESIZE];	
	int id;
	float score;
	struct list_head node;
};

int main(void)
{
	struct stu_st *p;
	struct list_head *pos;

	// 初始化头结点
	LIST_HEAD(mylist);		

	for (int i = 0; i < 3; i++) {
		p = malloc(sizeof(*p));
		snprintf(p->name, NAMESIZE, "stu%d", i+1);
		p->id = i + 1;
		p->score = 100 - i;
		list_add_tail(&p->node, &mylist);
	}

	list_for_each(pos, &mylist) {
		p = hlist_entry(pos, struct stu_st, node);
		printf("%s %d %f\n", p->name, p->id, p->score);
	}
	

	return 0;
}

