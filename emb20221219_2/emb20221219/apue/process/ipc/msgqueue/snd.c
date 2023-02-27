#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "proto.h"

int main(int argc, char *argv[])
{
	key_t key;
	int msgid;
	msg_t buf;
	
	if (argc < 2) {
		buf.stu.id = 1;
		strcpy(buf.stu.name, "hello");
	} else if (argc < 3) {
		strcpy(buf.stu.name, "hello");
	} else {
		buf.stu.id = atoi(argv[1]);
		strncpy(buf.stu.name, argv[2], NAMESIZE);
	}

	key = ftok(PATH, PROJ_ID);
	if (-1 == key) {
		perror("ftok()");
		exit(1);
	}

	// 创建/获取消息队列实例
	msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0600);
	if (-1 == msgid) {
		if (errno == EEXIST) {
			// 获得
			msgid = msgget(key, 0);
		} else {
			perror("msgget()");	
			exit(1);
		}
	}

	// 发消息
	msgsnd(msgid, &buf, sizeof(struct stu_st), 0);

	return 0;
}

