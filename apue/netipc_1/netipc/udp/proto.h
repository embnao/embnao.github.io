#ifndef __PROTO_H__
#define __PROTO_H__

#define SERVERIP	"192.168.53.240"
#define SERVERPORT	1122

#define NAMESIZE	32

// 对话格式
struct msg_st {
	int8_t id;
	char name[NAMESIZE]; // char *name;绝对不可，不能有指针
}__attribute__((packed));

#endif

