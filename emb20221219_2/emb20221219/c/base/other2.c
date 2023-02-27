#include <stdio.h>

int main(void)
{
	// sizeof()
	int n, m;

	printf("sizeof(n) : %ld\n", sizeof(n));
	printf("sizeof(int) : %ld\n", sizeof(int));
	printf("sizeof n : %ld\n", sizeof n);
	// char(1) short(2) int(4) long(8) long long(8) float(4) double(8) long double(16)

	// 自增自减
	m = 1;
	n = m++; // n = m, m += 1
	printf("n:%d, m:%d\n", n, m);
	n = ++m; // m += 1 n = m
	printf("n:%d, m:%d\n", n, m);

	// 面试题
	m = 1;
	printf("%ld\n", sizeof(++m));
	printf("m:%d\n", m);

	// 逗号运算符:至左向右依次执行，最后一个表达式的值是整个逗号运算的结果值
	n = (m++, m + 2, m + 10);
	printf("n:%d\n", n);

	return 0;
}

