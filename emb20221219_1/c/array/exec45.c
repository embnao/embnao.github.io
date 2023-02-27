#include <stdio.h>

#define N	20

static char lower(char c);
static char upper(char c);
static int is_lower(char c);
static int is_upper(char c);
static int is_letter(char c);

int main(void)
{
	char str[N] = {};
	int i;

	printf("str:");
	fgets(str, N, stdin);

	for (i = 0; str[i]; i++) {
		if (is_letter(str[i])) {
			if (is_upper(str[i]))	
				str[i] = lower(str[i]);
			else if (is_lower(str[i]))
				str[i] = upper(str[i]);
		}
	}

	puts(str);

	return 0;
}

static int is_letter(char c)
{
	return is_upper(c) || is_lower(c); 
}

static char upper(char c)
{
	return c - ('a' - 'A');
}

static char lower(char c)
{
	return c + ('a' - 'A');
}

static int is_upper(char c)
{
	return c >= 'A' && c <= 'Z';
}

static int is_lower(char c)
{
	return c >= 'a' && c <= 'z';
}



