// 预处理指令: 头文件多次包含，只展开一次
#ifndef __OP_H // 条件编译
#define __OP_H

// 函数(接口)声明
// extern可以省略，如不写，编译器会加
extern int add_2_num(int a, int b);

int sub_2_num(int a, int b);

extern int div_2_num(int a, int b);

#endif

