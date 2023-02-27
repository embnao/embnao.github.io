/*
	读入一个三位整型数，求这个三位整型数的逆序数
	
	786--->687
 */
#include <stdio.h>

int main(void)
{
	int num;
	int rev_num;

	printf("请输入一个三位数:");
	scanf("%d", &num);

	if (!(num >= 100 && num < 1000)) {
		printf("这也不是三位数啊\n");
	} else {
		rev_num = (num % 10) * 100 + \
				  (num / 10 % 10) * 10 + \
				  num / 100;
		printf("%d的到序数为：%d\n", num, rev_num);
	}

	return 0;
}

