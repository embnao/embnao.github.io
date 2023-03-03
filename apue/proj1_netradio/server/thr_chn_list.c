
#include "thr_chn_list.h"
#include "../proto/cs_proto.h"

struct list_msg {
	struct media_chn_list *mlib;
	int n;
};

static void *thr_list(void *s)
{
	struct list_msg *my_list = s;	
	struct chn_list *snd_list;
	int sum_len;
	struct list_entry *entry;
		
	// 遵循协议约定的数据类型，组织好频道列表的数据包，周期性发送
	// 包总长
	sum_len = sizeof(int8_t);
	for (int i = 0; i < my_list->n; i++) {
		// 当前频道列表的数据包大小
		sum_len += (strlen((my_list->mlib)[i].descr) + sizeof(int8_t) + sizeof(int8_t) + 1);
	}
	snd_list = malloc(sum_len);
	snd_list->chnid = CHN_LIST_ID;
	pos = 0;
	for (int i = 0; i < my_list->n; i++) {
		entry_len = (strlen((my_list->mlib)[i].descr) + sizeof(int8_t) + sizeof(int8_t) + 1)
		entry = malloc(entry_len);
		entry->chnid = (my_list->mlib)[i]->chnid;
		entry->len = entry_len;
		strcpy(entry->descr, (my_list->mlib)[i]->descr);
		memcpy((char *)snd_list->list+pos, entry, entry_len);
		pos += entry_len;
		free(entry);
		entry = NULL;
	}

	while (1) {
		sendto();	
		sleep(1);
	}


}

int thr_list_create(struct media_chn_list *mlib, int n)
{
	pthread_t list_tid;
	struct list_msg *my_list = malloc(sizeof(*my_list));
	int err;

	my_list->mlib = mlib;
	my_list->n = n;
	

	// 创建频道列表线程
	err = pthread_create(&list_tid, NULL, thr_list, my_list);
	if (err) {
		fprintf(stderr, "pthread_create():%s\n", strerror(err));
		free(my_list);
		return -1;
	}
	// 分离
	pthread_detach(list_tid);

	return 0;
}

