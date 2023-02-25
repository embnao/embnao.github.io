#include <stdio.h>

int mystrlen(const char *p);
char *mystrcpy(char *dest, const char *src);
char *mystrstr(const char *long_str, const char *short_str);
int mystrcmp(const char *s1, const char *s2);
char *mystrcat(char *dest, const char *src);

int main(void)
{
	char str[100] = "hello world";
	char *ptr = "class";

	printf("%d\n", mystrlen(str));

	// printf("%s\n", mystrcpy(str, ptr));

	printf("%s\n", mystrcat(str, ptr));

	printf("%d\n", mystrcmp("hello", "hello"));
	printf("%d\n", mystrcmp("hi", "hello"));
	printf("%d\n", mystrcmp("ai", "hello"));

	printf("%s\n", mystrstr("hellllloworld", "llow"));
	printf("%s\n", mystrstr("hellllloworld", "lda") == NULL ? "不是子串" : "找到了");
	printf("%s\n", mystrstr("hellllloworld", "lllm") == NULL ? "不是子串" : "找到了");

	return 0;
}

// 字符串长度
int mystrlen(const char *p)
{
	int len = 0;

	/*
	while (*p++) {
		len ++;
	}
	*/

	while (p[len++])
		;

	return len - 1;
}

// 字符串的复制
char *mystrcpy(char *dest, const char *src)
{
	char *ret;

	ret = dest;

	while (*dest++ = *src++) 
		;

	return ret;
}

// 字符串拼接
char *mystrcat(char *dest, const char *src)
{
	int i;
	// 找到dest的'\0'
	for (i = 0; dest[i]; i++)
		;
	mystrcpy(dest + i, src);

	return dest;
}

// 比较
int mystrcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1) {
		s1 ++;
		s2 ++;	
	}
	return *s1 - *s2;
}

// 找子串
char *mystrstr(const char *long_str, const char *short_str)
{
	int i, j;
	int k;
	int flag = 1;

	for (i = 0; long_str[i]; i++) {
		if (long_str[i] == short_str[0]) {
			k = i + 1;	
			flag = 1; // 默认相等
			for (j = 1; short_str[j]; j++, k++) {
				if (long_str[k] != short_str[j]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				return (char *)(long_str + i);	
			}
		}
	}

	return NULL;
}



