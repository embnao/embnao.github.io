#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义类型
typedef int (*cmp_t)(const void *, const void *);
typedef int a;

a b = 100;

void sort_arr(void *arr, int nmemb, int size, cmp_t cmp);

int str_cmp(const void *s1, const void *s2)
{
	char **ps1 = (char **)s1;
	char **ps2 = (char **)s2;

	return strcmp(*ps2, *ps1);
}

int main(int argc, char *argv[])
{
	sort_arr(argv, argc, sizeof(char *), str_cmp);		

	for (int i = 0; i < argc; i++)
		puts(argv[i]);

	return 0;
}

// 通用的排序
void sort_arr(void *arr, int nmemb, int size, cmp_t cmp)
{
	int i, j;
	void *k = malloc(size); // 选择

	for (i = 1; i < nmemb; i++) {
		// 选
		memcpy(k, (char *)arr + i * size, size);	
		// 有序序列每一个元素
		for (j = i - 1; j >= 0; j --) {
			if (cmp((char *)arr + j * size, k) > 0) {
				memcpy((char *)arr + (j + 1) * size, (char *)arr + j * size, size);		
			} else
				break;
		}
		memcpy((char *)arr + (j + 1) * size, k, size);
	}

	free(k);
	k = NULL;
}



