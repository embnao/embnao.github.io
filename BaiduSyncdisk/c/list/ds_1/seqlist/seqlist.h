#ifndef __SEQLIST_H__
#define __SEQLIST_H__

/*
 顺序表
 	通用型数组---》存储任意的数据类型
 */
// 抽象数据类型 --->顺序表
typedef struct {
	void *p; // 存储数组的起始地址
	int nmemb; // 成员个数
	int size; // 每个成员的字节大小
}seqlist_t;

// 比较函数类型
typedef int (*cmp_t)(const void *data, const void *key);
// 打印函数
typedef void (*pri_t)(const void *data);

// 接口的声明
// 初始化顺序表结构
extern seqlist_t *seqlist_init(int size);

// 增
extern int seqlist_add(seqlist_t *s, const void *data);

// 查
extern void *seqlist_search(const seqlist_t *s, const void *key, cmp_t cmp);

// 删
extern int seqlist_delete(seqlist_t *s, const void *key, cmp_t cmp);

// 遍历
extern void seqlist_traval(const seqlist_t *s, pri_t pri);

// 释放
extern void seqlist_destroy(seqlist_t *s);
#endif

