#ifndef __MEDIIA_LIB_H__
#define __MEDIIA_LIB_H__

#include <stdint.h>

/*
 解析媒体库，提供获取频道列表和读取频道数据两个功能
 */
#define MEDIALIB	"/home/zhangzongyan/media"	

// 抽象本模块需要的数据类型
struct mlib_chn_list {
	int8_t chnid;
	char *descr;
};

/*************************************
获取频道列表
*mlib:频道列表结构的起始地址
*chn_nr:频道个数
return: 0 成功 非0失败
 *************************************/ 
int get_chn_list(struct mlib_chn_list **mlib, int *chn_nr);

/*************************************
获取频道数据 
chnid:要读取的频道号
buf:存放读取数据的buf
size:请求读取的字节个数
return:读到的字节个数
*************************************/
ssize_t read_chn_data(int8_t chnid, char *buf, size_t size);


#endif

