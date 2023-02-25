#include <stdio.h>

/*
	*
	++	
 */

int main(void)
{
	int arr[] = {1, 5, 3, 9, 4, 6, 7, 8};
	int *p;
	int *a, b;

	p = arr;

	printf("*p++:%d\n", *p++); // 假如printf函数的第二个参数是n n = *p++;
	printf("*(p++):%d\n", *(p++)); // *p p++
	printf("(*p)++:%d\n", (*p)++); // *p (*p)++ 3-->4
	printf("*++p:%d\n", *++p);
	printf("++*p:%d\n", ++*p);


	return 0;
}
	
