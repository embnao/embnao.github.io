#include <stdlib.h>

int max3num(int a, int b, int c)
{
	int r;

	return (r = (a > b ? a : b)) > c ? r : c;
}

static int __add(int a, int b)
{
	return a + b;
}

static int __sub(int a, int b)
{
	return a - b;
}

static int __mul(int a, int b)
{
	return a * b;
}

static int __div(int a, int b)
{
	return a / b;
}

int op2num(int a, int b, char op)
{
	int ret;
	switch (op)	{
		case '+':
			ret = __add(a, b);
			break;
		case '-':
			ret = __sub(a, b);
			break;
		case '*':
			ret = __mul(a, b);
			break;
		case '/':
			ret = __div(a, b);
			break;
		default:
			// 异常
			abort();
			break;
	}

	return ret;
}

static int __factor(int n)
{
	int sum = 1;

	while (n > 0) {
		sum *= n--;
	}
	return sum;
}

int factorial_n(int n)
{
	int i; 
	int sum = 0;

	for (i = 1; i <= n; i++) {
		sum += __factor(i);	
	}

	return sum;
}

