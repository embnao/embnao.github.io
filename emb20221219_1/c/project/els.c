#include <stdio.h>
#include "els.h"

// 图形数组
int row = 1; // 相对背景行列
int col = 5;
struct graph {
	int arr[N][N];
}blocks[GRAPHNUM][CHANGENUM];
// 随机图形
int cur_graph, cur_change, cur_color;

// 背景数组
enum {GAP, BLOCK, BAND};// 枚举数组成员的值 1方块 2边界和停留的方块 0空
int bg[ROW][COL];

// 颜色数组
int color[ROW][COL];

// 初始化背景数组
static void __init_bg()
{
	int i, j;	

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1)
				bg[i][j] = BAND;// 边界
			else	
				bg[i][j] = GAP;
		}
	}
}	

// 画背景
void draw_bg()
{
	int i, j;

	__init_bg();
	printf("\033[2J");
	printf("\033[%d;%dH", X, Y);
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			if (BAND == bg[i][j]) {
				if (i == 0 || i == ROW - 1) {
					printf("==");
				} else if (j == 0 || j == COL - 1) {
					printf("||");
				}
			} else
				printf("  ");
		}
		printf("\n\033[%dC", Y - 1);
	}

	printf("\033[0m");
}

static void __debug_block(void)
{
	int i, j, m, n;

	for (i = 0; i < GRAPHNUM; i++) {
		for (j = 0; j < CHANGENUM; j++) {
			for (m = 0; m < N; m++) {
				for (n = 0; n < N; n++) {
					printf("%d", blocks[i][j].arr[m][n]);
				}
				printf("\n");
			}
		}
	}

}

// 初始化所有的图形
void init_graph(void)
{
	int i, j;
	int m, n;

	// z
	for (i = 1, j = 1; i < 3; i++, j++)	{
		blocks[0][0].arr[i][j] = 1;
		blocks[0][0].arr[i][j+1] = 1;
	}
	// 反z
	for (i = 1, j = 2; i < 3; i++, j--)	 {
		blocks[1][0].arr[i][j] = 1;	
		blocks[1][0].arr[i][j+1] = 1;	
	}
	// 7 反7 土
	for (i = 1, j = 2; i < 4; i++) {
		blocks[2][0].arr[i][j] = 1;	// 7
		blocks[3][0].arr[i][j] = 1; // 反7
		blocks[4][0].arr[i][j] = 1;
		if (i == 1) {
			blocks[2][0].arr[i][j-1] = 1;
			blocks[3][0].arr[i][j+1] = 1;
		}
		if (i == 2)
			blocks[4][0].arr[i][j+1] = 1;
	}
	// 1
	for (i = 0; i < 4; i++)
		blocks[5][0].arr[i][1] = 1;
	// 方块
	for (i = 1; i < 3; i++) {
		for (j = 1; j < 3; j++)
			blocks[6][0].arr[i][j] = 1;
	}

	// 旋转
	for (i = 0; i < GRAPHNUM; i++) {
		for (j = 0; j < CHANGENUM - 1; j++) {
			for (m = 0; m < N; m++)	{
				for (n = 0; n < N; n++) {
					if (blocks[i][j].arr[m][n])
						blocks[i][j+1].arr[N-1-n][m] = blocks[i][j].arr[m][n];
				}
			}
		}
	}
	// __debug_block();
}

// 图形写入背景数组
void write_in_bg(void)
{
	int i, j;	

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (blocks[cur_graph][cur_change].arr[i][j])
				bg[row+i][col+j] = blocks[cur_graph][cur_change].arr[i][j];
		}
	}
}

static void __select_color(int color)
{
	printf("\033[%dm", 40 + color);
}

// 展示背景数组
void show_bg_arr(void)
{
	int i, j;
	
	printf("\033[%d;%dH", X + 1, Y + 2); // 去掉边框
	for (i = 1; i < ROW - 1; i++) {
		for (j = 1; j < COL - 1; j++) {
			if (bg[i][j] == BLOCK) {
				// 游戏方块
				__select_color(cur_color);
				printf("[]");
			} else if (bg[i][j] == BAND) {
				// 已停定的方块
				printf("[]");
			} else
				// 空白
				printf("  ");
			printf("\033[0m");
		}
		printf("\n\033[%dC", Y + 1);
	}
	printf("\033[0m");
}

// 清除移动前的值
static void __cancel_block(int direct)
{
	int pre_row, pre_col;
	int i, j;

	pre_row = pre_col = 0;
		
	switch(direct) {
		case LEFT:
			pre_col = 1;
			break;
		case RIGHT:
			pre_col = -1;
			break;
		case DOWN:
			pre_row = -1;
			break;
		default:
			break;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (bg[row+i+pre_row][col+j+pre_col]) {
				bg[row+i+pre_row][col+j+pre_col] = GAP;
			}
		}
	}
}

// 运动
void block_move(int direct)
{
	int i, j;
	switch (direct) {
		case LEFT:
			col--;			
			break;
		case RIGHT:
			col++;
			break;
		case DOWN:
			row++;	
			break;
		case UP:
			// 图形变换
			break;
		default:
			break;
	}

	// 先移动，再清上一个图形
	__cancel_block(direct);
	write_in_bg();
	show_bg_arr();
}














