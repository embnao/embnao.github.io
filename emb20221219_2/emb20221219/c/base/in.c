#include <stdio.h>

/*
 c标准类型：
 	整型
		short	int		long	long long
	实型
		float	double  long double
	字符型
		char
	空类型
		void
	复合类型
		struct union enum
 变量:
 	定义
	初始化
 关键字：
 	在c语言中，有特定含义的
	类型:char short int  long float doule void struct union enum
	if else for  while do continue break switch case......
 标识符:
 	变量名、函数名、类型名
 	命名规则：由字符、数字、下划线组成，数字不能开头，避开c关键字,最好顾名思义
 c运算符:
 	man operator
	算术运算符:
		+ - * / % 
	关系运算符:
		== != > < >= <=
	逻辑运算符:
		&& || !
	位运算符
		& | ~ ^ << >>
	赋值运算符
		= += -= *= ....
	三目运算符 / 关系运算符
		? : 
	其他:
		* [] . -> & + - sizeof ++ -- (type) () ,

 */

int main(void)
{
	// 变量的定义
	int num;
	/*
	// 格式化读入
	printf("num:");
	scanf("%d", &num);

	printf("num的值为%d\n", num);
	*/

	// 演示%
	num = 798; // 每一位
	printf("个位:%d, 十位:%d, 百位:%d\n", \
			num % 10, num / 10 % 10, num / 100);
	
	printf("%d\n", num > 1000);

	// 演示逻辑运算符
	char c;

	scanf("%c", &c);

	printf("%d\n", c >= 'A' && c <= 'Z');

	printf("%d\n", !(c < 'A' || c > 'Z'));
	// 写一个表达式: c既不是大写字符 也不是小写字母	

	printf("%d\n", !(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'));

	return 0;
}

