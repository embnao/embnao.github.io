#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include "els.h"

extern int cur_graph, cur_color, cur_change;

int main(void)
{
	struct termios old, new;

	int c;
	// 初始化所有的游戏图形
	init_graph();
	// 初始化背景数组并画背景
	draw_bg();

	// 随机产生游戏图形
	srand(getpid());
	cur_graph = rand() % GRAPHNUM;
	cur_change = rand() % CHANGENUM;
	cur_color = rand() % 8;

	write_in_bg(); // 产生的游戏图形写入背景
	show_bg_arr(); // 展示棋盘

	// 关闭输入文件的回显和缓存
	tcgetattr(0, &old);
	new = old;
	new.c_lflag = new.c_lflag & ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &new);

	while (1) {
		c = getchar();
		switch (c) {
			case 'a':
				block_move(LEFT);
				break;
			case 'd':
				block_move(RIGHT);
				break;
			case 's':
				block_move(DOWN);
				break;
		}
	}

	return 0;
}

