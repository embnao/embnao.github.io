#include <stdio.h>

#define N	20

static int is_space(char c);
static int is_digital(char c);
static int is_letter(char c);
int main(void)
{
	char str[N] = {};
	int letter_cnt = 0;
	int digital_cnt = 0;
	int space_cnt = 0;
	int other_cnt = 0;
	int i;

	printf("string:");
	fgets(str, N, stdin);

	for (i = 0; str[i]; i++) {
		if (is_letter(str[i]))
			letter_cnt ++;
		else if (is_digital(str[i]))
			digital_cnt ++;
		else if (is_space(str[i]))
			space_cnt ++;
		else 
			other_cnt ++;
	}
	printf("字母:%d, 数字:%d, 空格:%d, 其他:%d\n", \
			letter_cnt, digital_cnt, space_cnt, other_cnt);

	return 0;
}

static int is_letter(char c)
{
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

static int is_digital(char c)
{
	return c >= '0' && c <= '9';
}

static int is_space(char c)
{
	return c == ' ';
}


