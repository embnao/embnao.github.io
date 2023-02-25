#include <stdio.h>
/*
 分支语句
 if (condition) {
 
 }

 if (condition) {
 
 } else { // 否则
 
 }

 // 多分支
 if (conditon1) {
 
 } else if (condition2) {
 
 } else if (condition3) {
 
 } ...

 */

int main(void)
{
	// 读入一个非负整型数并输出
	int n;

	printf("n:");
	scanf("%d", &n);
 
	if (n >= 0) {
		printf("成功读入一个非负整型数\n");
	}

	return 0;
}

