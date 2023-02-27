#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h> // man 2 signal

// 显示图形
#define	GRAPH	7
#define CHANGE	4
#define N		4
static int blocks[GRAPH][CHANGE][N][N] = {
	{
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		}, 
		{
			{0, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		}, 
		{
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		}
	}
};

static int cur_graph, cur_change;
static int start_x = 3, start_y = 5;
static int cur_color;

void show();

// 一旦信号来了 自动调用此函数
static void sig_handler(int s)
{
	alarm(1);
	start_y ++;
	show();
}

int main(void)
{
	srand(getpid());

	// cur_graph = rand() % GRAPH;
	cur_graph = 0;
	cur_change = rand() % CHANGE;
	cur_color = 40 + rand() % 8;

	show();

	// 自由下落 周期性产生信号，信号一旦产生调用信号处理函数
	// 当SIGALRM信号产生了，就会调用sig_handler函数
	signal(SIGALRM, sig_handler);
	alarm(1); // 1s后产生SIGALRM信号

	while (1) {
		// 读入游戏输入'a''s''w''d'
	}

	return 0;
}

// 展示当前图形
void show()
{
	int i, j;

	// 清屏
	printf("\033[2J");
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (blocks[cur_graph][cur_change][i][j]) {
				// 打印方块
				printf("\033[%dm\033[%d;%dH[]", cur_color, i + start_y, j * 2 + start_x);
				printf("\033[0m");
			}
		}
	}

	// 刷新缓存
	fflush(NULL);

}

