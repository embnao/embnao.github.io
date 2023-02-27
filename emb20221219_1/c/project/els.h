#ifndef __ELS_H
#define __ELS_H

#define N			4
#define GRAPHNUM	7
#define CHANGENUM	4
#define X	5
#define	Y	12 // 背景初始行列
#define ROW	20
#define COL	14 // 数组大小

enum {LEFT, RIGHT, DOWN, UP};

extern void draw_bg();
extern void init_graph(void);
extern void show_bg_arr(void);
extern void write_in_bg(void);
extern void block_move(int direct);

#endif

