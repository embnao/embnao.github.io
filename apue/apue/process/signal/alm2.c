#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static void sig_handler(int s)
{
	write(1, "!", 1);
}

int main(void)
{
	signal(2, sig_handler);

	// 自定义一个时钟接口，能够实现响应所有的时钟
	// ***!**!*****!*****
	my_alarm(10);
	my_alarm(3);
	my_alarm(5);

	while (1) {
		write(1, "*", 1);
		sleep(1);
	}

	return 0;
}

