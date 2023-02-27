#include <stdio.h>

int main(void)
{
	int arr[3] = {1, 2, 3};
	int *p = arr;
	// 数组指针
	int (*q)[3]= &arr;
	int arrarr[2][3] = {};
	q = arrarr;

	printf("p:%p\n", p);	
	printf("q:%p\n", q);

	printf("p + 1:%p\n", p + 1);	
	printf("q + 1:%p\n", q + 1);

	return 0;
}

