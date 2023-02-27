
// 定义---》分配存储空间
int test;

// extern int test2; // 只声明，不定义(不分配空间)
extern int test2 = 200; // 初始化了，定义并声明

// 只能在本文件中使用, 鼓励全局变量用static修饰
static int test3;

int add_2_num(int a, int b)
{
	test = 10000;

	return a + b;
}

int sub_2_num(int a, int b)
{
	return a - b;
}

// 判断整型数是否能做除数
static int is_div(int n)
{
	return !(n == 0);
}

int div_2_num(int a, int b)
{
	if (is_div(b))
		return a / b;
	// 产生异常
}

