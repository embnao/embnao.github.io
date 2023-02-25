#include <stdlib.h>
#include <string.h>
#include "seqlist.h"

seqlist_t *seqlist_init(int size)
{
	seqlist_t *s = malloc(sizeof(seqlist_t));
	if (NULL == s)
		return NULL;
	s->p = NULL;
	s->nmemb = 0;
	s->size = size;

	return s;
}

int seqlist_add(seqlist_t *s, const void *data)
{
	// 多开辟size字节
	s->p = realloc(s->p, (s->nmemb + 1) * s->size);
	if (NULL == s->p)
		return -1;
	// copy数据
	memcpy((char *)s->p + s->nmemb * s->size, data, s->size);
	s->nmemb++;

	return 0;
}

// 返回待查找元素的下标
static int __search(const seqlist_t *s, const void *key, cmp_t cmp)
{
	int i;

	for (i = 0; i < s->nmemb; i++) {
		if (cmp((char *)s->p + i * s->size, key) == 0)
			return i;
	}

	return -1;
}

void *seqlist_search(const seqlist_t *s, const void *key, cmp_t cmp)
{
	int ind;
	
	ind = __search(s, key, cmp);
	if (ind == -1)
		return NULL;
	return (char *)s->p + ind * s->size;
}


int seqlist_delete(seqlist_t *s, const void *key, cmp_t cmp)
{
	// 找
	int i = __search(s, key, cmp);

	// 没找到
	if (-1 == i)
		return -1;

	// 找到了--->删
	memmove((char *)s->p + i * s->size, (char *)s->p + (i + 1) * s->size, (s->nmemb - (i + 1)) * s->size);
	s->nmemb--;
	s->p = realloc(s->p, s->nmemb * s->size);
	if (s->p == NULL)
		return -1;
	return 0;
}

void seqlist_traval(const seqlist_t *s, pri_t pri)
{
	int i;

	for (i = 0; i < s->nmemb; i++) {
		pri((char *)s->p + i * s->size);
	}
}

void seqlist_destroy(seqlist_t *s)
{
	free(s->p);
	s->p = NULL;
	free(s);
	s = NULL;
}

