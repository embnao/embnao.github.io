#ifndef __PROTO_H__
#define __PROTO_H__

#define NAMESIZE	32

#define PATH	"/etc/passwd"
#define PROJ_ID	1

struct stu_st {
	int id;
	char name[NAMESIZE];
};

typedef struct {
	long mtype; /* > 0*/ 
	struct stu_st stu;
}msg_t;

#endif

