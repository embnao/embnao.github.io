/*
man 2 alarm(2)周期性产生SIGALRM信号
现要求使用此信号，将argv[1]按照指定速率写到终端
 */

static int token;

static void sig_handler(int s)
{
	// 每秒钟将token 置1
	alarm(1);
}

int main(void)
{
	signal(SIGALRM, sig_handler);
	alarm(1);


	while (1) {
		while (!token)
			pause();
		token = 0;
		// io
	}

}


