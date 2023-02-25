#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define BUFSIZE	64

static char file_type(struct stat st);
static char *file_mode(struct stat st);
static int file_nlink(struct stat st);
static char *file_owner_name(struct stat st);
static char *file_group_name(struct stat st);
static long file_size(struct stat st);
static char *file_mtime(struct stat st);

int main(int argc, char *argv[])
{
	struct stat res;

	if (argc < 2)
		return 1;
	if (-1 == stat(argv[1], &res)) {
		perror("stat()");
		return 1;
	}

	printf("%c%s %d %s %s %ld %s %s\n", file_type(res), file_mode(res), \
			file_nlink(res), file_owner_name(res), file_group_name(res), \
			file_size(res), file_mtime(res), argv[1]);

	return 0;
}

/*
	类型 
 */
static char file_type(struct stat st)
{
	char ret;

	if ((st.st_mode & S_IFMT) == S_IFREG)
		ret = '-';
	else if ((st.st_mode & S_IFMT) == S_IFDIR)
		ret = 'd';

	return ret;
}

/*
 文件权限
 */

static char *file_mode(struct stat st)
{
	int modes[] = {S_IRUSR, S_IWUSR, S_IXUSR, \
	S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};	
	static char s[] = "rwxrwxrwx";
	int i;
	
	for (i = 0; i < sizeof(modes) / sizeof(int); i++) {
		if (!(st.st_mode & modes[i]))
			s[i] = '-';
	}

	return s;
}

/*
  硬链接个数
 */
static int file_nlink(struct stat st)
{
	return st.st_nlink;	
}

/*
 owner
 */
static char *file_owner_name(struct stat st)
{
	struct passwd *pwd = getpwuid(st.st_uid);

	return pwd->pw_name;
}

/*
 	group name
 */
static char *file_group_name(struct stat st)
{
	struct group *gr = getgrgid(st.st_gid);

	return gr->gr_name;
}

/*
 	字节大小 != 所占磁盘空间大小
 */
static long file_size(struct stat st)
{
	return st.st_size;
}

/*
 	mtime--->时间字符串
 */
static char *file_mtime(struct stat st)
{
	static char buf[BUFSIZE] = {};

	// 时间结构体
	struct tm *tmp = localtime(&st.st_mtime);
	// if error
	// 格式化时间字符串
	strftime(buf, BUFSIZE, "%m月 %d %H:%M", tmp);

	return buf;
}





