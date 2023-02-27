#include <stdio.h>

// 日历

int is_leap(int year);
int month_days(int month, int year);

int main(void)
{
	int y, m;
	int i;
	int sumdays = 0;
	int week, monthdays;

	do {
		printf("请输入日期(年,月):");
		scanf("%d,%d", &y, &m);
	} while(!(m >= 1 && m <= 12 && y >= 1990));

	// 1990~y-1
	for (i = 1990; i < y; i++)
		sumdays += (is_leap(i) ? 366 : 365);
	// y.1 ~ y.m
	for (i = 1; i < m; i++)
		sumdays += month_days(i, y);
	// y.m.1
	sumdays += 1;

	week = sumdays % 7;
	monthdays = month_days(m, y);

	// 打印
	printf("      %d月%d\n", m, y);
	printf("日 一 二 三 四 五 六\n");
	for (i = 0; i < week; i++)
		printf("   ");
	for (i = 1; i <= monthdays; i++) {
		printf("%2d%c", i, (i + week) % 7 ? ' ' : '\n');
	}
	printf("\n");

	return 0;
}

/*
 求出月份对应的天数
 */
int month_days(int month, int year)
{
	int days;

	if (!(month >= 1 && month <= 12))
		return -1;
	switch (month) {
		case 1: 
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days = 30;
			break;
		case 2:
			days = 28 + is_leap(year);
			break;
		default:
			break;
	}

	return days;
}


/*
 判断平年闰年
 */
int is_leap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;		
}



