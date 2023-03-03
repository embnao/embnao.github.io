#ifndef __THR_LIST_H__
#define __THR_LIST_H__

#include "media_lib.h"

/*
周期性向多播组发送频道列表
mlib:频道列表结构的起始地址
n:频道个数
 */
int thr_list_create(struct media_chn_list *mlib, int n); 

#endif

