/*
变量 
	局部变量
	全局变量
	修饰变量的关键字
		auto
static:
1. 修饰局部变量，局部静态变量，改变生存周期
2. 修饰全局变量, 限制作用域在本文件(默认全局变量的作用域整个进程(多文件))
3. 修饰函数,限制作用域到只能在本文件调用
		const
register:寄存器变量
volatile:易失变量,防止编译优化
extern:专门修饰全局
 */
#include <stdio.h>

int g; // 全局变量 bss 值一定0
int g2 = 100; // 全局变量 data
/*
 作用域:
 	整个进程
 生存周期:
 	进程结束
 */

int test(void);
int main(void)
{
	auto int n; // 局部变量 栈 值随机
	int n2 = 1000; // 局部变量 栈
	const int c = 100; // 只读变量

	// c ++;

	/*
	 作用域：从定义开始到函数结束
	 生存周期: 从定义开始到函数结束
	 */
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());


	return 0;
}

/*
 局部静态
 */
int test(void)
{
	// 局部静态变量:生存周期长了，到整个进程结束，作用域保留局部特点
	// 未初始化bss 已初始化data
	static int i;
	// int i = 0;

	i++;
	return i;
}



