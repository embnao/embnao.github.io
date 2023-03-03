#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>

#include "media_lib.h"

#define BUFSIZE	1024

/***************************
 
解析目录:
	分配chnid(列表)
	频道描述(列表)
	当前频道下所有音乐文件路径 (read_chn_data)
	读到了频道音乐文件的哪一个index(read_chn_data)
	当前所读文件的文件描述符(默认打开第一个文件) (read_chn_data)
 ****************************/
// 频道目录的数据类型抽象
struct chn_context_st {
	int8_t chnid;
	char *descr;
	char **all_paths; // all_paths存储所有路径的指针数组的起始地址
	int mp3_nr; // 当前频道下有多少个音频文件
	int cur_ind; // 当前读到了第几个文件
	int fd; // 正在读的文件描述符
};

//contexts存储动态开辟的指针数组的起始地址
static struct chn_context_st **contexts;

static struct chn_context_st *get_chn_context(const char *path)
{
	// path 频道路径
	DIR *dp = NULL;	
	struct dirent *entry = NULL;
	char buf[BUFSIZE] = {};
	struct chn_context_st *ret;
	FILE *fp = NULL;
	size_t n = 0;
	static int chn_id = 1;

	ret = malloc(sizeof(struct chn_context_st));
	if (NULL == ret) {
		perror("malloc()");
		return NULL;
	}
	ret->mp3_nr = 0;
	ret->all_paths = NULL;
	ret->cur_ind = 0;
	ret->descr = NULL;

	dp = opendir(path);
	if (NULL == dp) {
		perror("opendir()");
		return NULL;
	}

	while (1) {
		entry = readdir(dp);
		if (NULL == entry)
			break;
		if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
			continue;
		memset(buf, '\0', BUFSIZE);
		strcpy(buf, path);
		strcat(buf, "/");
		strcat(buf, entry->d_name);
		if (strcmp(entry->d_name, "descr.txt") == 0) {
			// 描述文件
			fp = fopen(buf, "r");
			if (NULL == fp) {
				goto ERROR;
			}
			getline(&ret->descr, &n, fp);	
		} else if (!strcmp(strchr(entry->d_name, '.'), ".mp3")) {
			ret->all_paths = realloc(ret->all_paths, (ret->mp3_nr + 1) * sizeof(char *));
			(ret->all_paths)[ret->mp3_nr++] = strdup(buf);	
		}
	}

	if (ret->mp3_nr == 0 || ret->descr == NULL) {
		goto ERROR;
	}
	ret->chnid = chn_id ++;

	ret->fd = open((ret->all_paths)[0], O_RDONLY);
	if (-1 == ret->fd)
		goto ERROR;

	return ret;

ERROR:
	free(ret);
	return NULL;
}

// 解析
static int mlib_parse(const char *path)
{
	// path 媒体库
	DIR *dp = NULL;	
	struct dirent *entry = NULL;
	char buf[BUFSIZE] = {};
	struct chn_context_st *p;
	int n = 1;
	int i;

	// 首先开辟一个结构体类型指针
	contexts = malloc(n * sizeof(struct chn_context_st *));

	dp = opendir(path);
	if (NULL == dp) {
		perror("opendir()");
		return -1;
	}

	/*
	   path-->"~/media"
	   chn1
	   		"descr.txt"
			"告白气球.mp3"
			"枫.mp3"
			"发如雪.mp3"
	   chn2
	   		"葫芦娃.mp3"
			"西游记.mp3"
			"大头儿子和小头爸爸.mp3"
	
	 */
	i = 0;
	while (1) {
		entry = readdir(dp);	
		if (NULL == entry)
			break;
	
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;

		// "chn1" ---> "~/media/chn1"
		memset(buf, '\0', BUFSIZE);
		strcpy(buf, path);
		strcat(buf, "/");
		strcat(buf, entry->d_name);
		p = get_chn_context(buf);	
		if (NULL == p)
			continue;
		contexts = realloc(contexts, (n + 1) * sizeof(struct chn_context_st *));
		contexts[i] = p;
		i++;
		n++;
	}
	contexts[i] = NULL;

	return 0;
}


int get_chn_list(struct mlib_chn_list **mlib, int *chn_nr)
{
	int i = 0;

	if (-1 == mlib_parse(MEDIALIB)) {
		fprintf(stderr, "mlib_parse() failed\n");
		return -1;
	}

	// 获取频道个数
	for (i = 0; contexts[i]; i++) {
		;
	}
	*chn_nr = i;
	*mlib = calloc(i, sizeof(struct mlib_chn_list));

	for (i = 0; contexts[i]; i++) {
		(*mlib)[i].chnid = contexts[i]->chnid;
		(*mlib)[i].descr = contexts[i]->descr;
	}

	return 0;
}

static int context_pos(int8_t chnid)
{
	for (int i = 0; contexts[i]; i++)
		if (contexts[i]->chnid == chnid)
			return i;
	return -1;
}

// 打开下一个文件
static int __open_next(struct chn_context_st *me)
{
	close(me->fd);
	me->cur_ind = (me->cur_ind + 1) % me->mp3_nr;
	me->fd = open((me->all_paths)[me->cur_ind], O_RDONLY);
	if (-1 == me->fd) {
		perror("open()");
		return -1;
	}

	return 0;
}

ssize_t read_chn_data(int8_t chnid, char *buf, size_t size)
{
	struct chn_context_st *my_chn_cont;
	int pos;
	int cnt;

	// 找到当前频道的结构
	pos = context_pos(chnid);
	if (pos == -1)
		return -1;
	my_chn_cont = contexts[pos];
	
	// 读size字节数据，存buf 
	while (1) {
		cnt = read(my_chn_cont->fd, buf, size);	
		if (-1 == cnt) {
			perror("read()");
			return -1;
		}
		if (0 == cnt) {
			// 当前音乐文件读取完成，打开下一个音乐文件，继续读
			// 关闭当前，打开下一个文件
			__open_next(my_chn_cont);

			continue;
		}
		break;
	}

	return cnt;
}


