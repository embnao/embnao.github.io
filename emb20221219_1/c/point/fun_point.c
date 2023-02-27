/*
 函数指针
 */
#include <stdio.h>

void test(void);
void show_arr(void *arr, int nmemb, int size, void (*p)(void *data));

static void pri_int(void *data)
{
	int *p = (int *)data;
	printf("%d ", *p);
}

static void pri_char(void *data)
{
	char *p = (char *)data;
	printf("%c ", *p);
}

int main(void)
{
	// 函数名就是函数的入口地址,类型由参数和返回值类型决定
	// p函数指针变量
	void (*p)(void) = test;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	char str[] = "class is over";
	char *s[] = {"红烧肉", "排骨炖豆角"};

	// p();
	// (*p)(); // *p跟p一样 不做运算
	// sizeof(数组名)整个数组所占的存储空间
	show_arr(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), pri_int);				
	show_arr(str, sizeof(str) / sizeof(char), sizeof(char), pri_char);


	return 0;
}

void test(void)
{
	printf("测试函数\n");
}

/*
 通用的打印数组函数
 */
void show_arr(void *arr, int nmemb, int size, void (*p)(void *data))
{
	int i;

	for (i = 0; i < nmemb; i++) {
		// 打印下标为i元素
		p((char *)arr + i * size);
	}
	printf("\n");
}


