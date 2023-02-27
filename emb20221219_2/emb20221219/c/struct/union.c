#include <stdio.h>

/*
 共用体---》联合体
 */
union data {
	int a;
	char b;
};

/*
 小端存储:低字节存低地址，高字节存高地址
 大端存储:低字节存高地址，高字节存低地址
 */

int main(void)
{
	union data d;
	
	d.a = 0x12345678;

	if (d.b == 0x78)
		printf("小端存储\n");
	else if (d.b == 0x12)
		printf("大端存储\n");

	return 0;
}

