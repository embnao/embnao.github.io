#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "proto.h"

int main(void)
{
	key_t key;
	int msgid;
	msg_t buf;
	
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

	msgrcv(msgid, &buf, sizeof(struct stu_st), 0, 0);
	printf("收到了 id:%d, name:%s\n", buf.stu.id, buf.stu.name);

	return 0;
}

