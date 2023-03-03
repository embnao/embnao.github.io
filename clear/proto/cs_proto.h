#ifndef __CS_PROTO_H__
#define __CS_PROTO_H__

#define MULTICAT_IP	"224.2.2.2"
#define RCV_PORT	1111
#define CHN_NR		200
#define CHN_LIST_ID	0	
#define MIN_CHN_ID	1
#define MAX_CHN_ID	200
#define MAXMSG		512

// 数据类型
// 单个频道
struct list_entry {
	int8_t chnid; // 频道号 MIN_CHN_ID ~ MAX_CHN_ID
	int8_t len; // 自述长度
	char descr[1]; // 变长结构体,频道描述的起始地址
}__attribute__((packed));
// 列表 有多少个频道就有多少个struct list_entry结构
struct chn_list {
	int8_t chnid; // 必须是CHN_LIST_ID
	struct list_entry list[1]; // 所有频道的结构
}__attribute__((packed));

// 数据
struct chn_data {
	int8_t chnid; // MIN_CHN_ID ~ MAX_CHN_ID
	char data[1];
}__attribute__((packed));

// 接收数据类型
union msg_st {
	int8_t chnid;
	struct chn_list chnlist;
	struct chn_data chndata;
};


#endif

