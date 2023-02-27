#ifndef __OP_H__
#define __OP_H__

// 增
int *arr_insert(int *p, int *nmemb, int n);

// 升级版插入 p是存储一级指针遍历的地址
int arr_insert_v2(int **p, int *nmemb, int n);

// 插拍,插入即有序
int arr_insert_sort(int **p, int *nmemb, int n);

// 查
int arr_find(const int *p, int nmemb, int key);

// 删
int *arr_delete(int *p, int *nmemb, int key);

// 改
int arr_update(int *p, int nmemb, int key, int newdata);

// 遍历
void arr_traval(const int *p, int nmemb);

// 销毁
void arr_destroy(int *p);

#endif

