#include <stdio.h>
#include <stdlib.h>

#include "media_lib.h"
// #include "thr_chn_list.h"
// #include "thr_chn_data.h"

int udp_socket_init();
int main(void)
{
	struct mlib_chn_list *mymlib = NULL;
	int nr = 0;

	// 初始化套接字
	udp_socket_init();

	// 获取频道列表
	get_chn_list(&mymlib, &nr);

	for (int i = 0; i < nr; i++) {
		printf("%d %s\n", mymlib[i].chnid, mymlib[i].descr);
	}

	/*
	// 启动发送频道列表的线程
	thr_chn_list(mymlib, nr);

	// 并发发送频道数据的线程模块--->线程池
	for (int i = 0; i < nr; i++) {
		thr_chn_data(mymlib[i].chnid);
	}

	pause();
*/
	exit(0);
}

int udp_socket_init()
{


}


