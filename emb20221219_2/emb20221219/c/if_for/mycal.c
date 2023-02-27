/*
 日历
 */
#include <stdio.h>

int main(void)
{
	// 已知1990.1.1是星期一
	int year, month;
	int sumdays = 0;
	int firstweek;
	int monthdays;
	int i;

	do {
		printf("请输入年/月:");
		scanf("%d/%d", &year, &month);
	} while(!(year >= 1990 && month >= 1 && month <= 12));

	// year.month.1是星期几?
	// 1990.1.1 ~ year.month.1有多少天 % 7
	for (i = 1990; i < year; i++) {
		sumdays += (i % 4 == 0 && i % 100 != 0 || i % 400 == 0 ? 366 : 365);
	}
	for (i = 1; i < month; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || \
				10 == i || i == 12)
			sumdays += 31;
		else if (4 == i || 6 == i || 9 == i || 11 == i)
			sumdays += 30;
		else {
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				sumdays += 29;
			else
				sumdays += 28;
		}
	}
	// month.1
	sumdays += 1;
	firstweek = sumdays % 7;
	printf("%d/%d/1是星期%d\n", year, month, firstweek);
	
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || \
			10 == month || month == 12)
		monthdays = 31;
	else if (4 == month || 6 == month || 9 == month || 11 == month)
		monthdays = 30;
	else {
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			monthdays = 29;
		else
			monthdays = 28;
	}

	// 打印
	printf("      %d月%d年\n", month, year);
	printf("日 一 二 三 四 五 六\n");
	for (i = 0; i < firstweek; i++)
		printf("   ");
	for (i = 1; i <= monthdays; i++) {
		printf("%2d%c", i, (i + firstweek) % 7 == 0 ? '\n' : ' ');
	}
	printf("\n");

	return 0;
}

