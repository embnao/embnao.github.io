#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <unistd.h>
#include <stdio.h>
#include <shadow.h>
#include <string.h>

/*
 密码的校验
 */

#define BUFSIZE	100

int main(void)
{
	char name[BUFSIZE] = {};
	char *pwd;
	struct spwd *sp;
	char *encryped;

	// 读入用户名和密码(待校验)
	printf("用户名:");
	fgets(name, BUFSIZE, stdin);
	// "root\n"
	*strchr(name, '\n') = '\0';
	pwd = getpass("密码:");
	
	// 获取用户对应的真正密码
	sp = getspnam(name);
	if (NULL == sp) {
		perror("getspnam()");
		return -1;
	}
	// 加密
	encryped = crypt(pwd, sp->sp_pwdp);
	if (NULL == encryped)
		return -1;

	// 比对
	if (strcmp(encryped, sp->sp_pwdp) == 0)
		printf("登录成功\n");
	else
		printf("鉴定错误\n");

	return 0;
}

