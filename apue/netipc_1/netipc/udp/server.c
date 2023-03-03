#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include "proto.h"

int main(void)
{
	struct sockaddr_in local_addr;
	struct sockaddr_in remote_addr;
	socklen_t remote_addr_len;
	int cnt;
	struct msg_st buf;

	int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1 == udp_socket) {
		perror("socket()");
		exit(1);
	}

	// 为套接字绑定本地地址
	local_addr.sin_family = AF_INET;
	// 网络字节序 htons(3)
	local_addr.sin_port = htons(SERVERPORT);
	// ip 点分十进制转化为uint32整型 inet_aton(3)
	inet_aton(SERVERIP, &local_addr.sin_addr);
	if (-1 == bind(udp_socket, (struct sockaddr *)&local_addr, sizeof(local_addr))) {
		perror("bind()");
		goto ERROR;
	}

	// 接受对端地址的时候，长度必须初始化
	remote_addr_len = sizeof(struct sockaddr_in);
	while (1) {
		cnt = recvfrom(udp_socket, &buf, sizeof(buf), 0, (void *)&remote_addr, &remote_addr_len);
		if (-1 == cnt) {
			perror("recvfrom()");
			goto ERROR;
		}
		printf("id:%d, name:%s\n", buf.id, buf.name);
		sendto(udp_socket, "ok", 3, 0, (void *)&remote_addr, remote_addr_len);
	}

	close(udp_socket);

	return 0;
ERROR:
	close(udp_socket);
	exit(1);
}


