#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include "proto.h"

#define BUFSIZE	128

int main(int argc, char *argv[])
{
	struct sockaddr_in remote_addr;
	struct msg_st sndbuf;
	char buf[BUFSIZE] = {};

	if (argc < 3)
		exit(1);

	int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1 == udp_socket) {
		perror("socket()");
		exit(1);
	}

	// bind(2)省略，内核自动绑定free的端口

	sndbuf.id = atoi(argv[1]);
	strncpy(sndbuf.name, argv[2], NAMESIZE);

	remote_addr.sin_family = AF_INET;
	remote_addr.sin_port = htons(SERVERPORT);
	inet_aton(SERVERIP, &remote_addr.sin_addr);

	sendto(udp_socket, &sndbuf, sizeof(sndbuf), 0, (void *)&remote_addr, sizeof(remote_addr));
	recvfrom(udp_socket, buf, BUFSIZE, 0, NULL, NULL);
	puts(buf);

	close(udp_socket);

	return 0;
ERROR:
	close(udp_socket);
	exit(1);
}


