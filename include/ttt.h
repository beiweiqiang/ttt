#ifndef TTT_TTT_H
#define TTT_TTT_H

#include <stdbool.h>
#define SIZE 3
#define ERROR_NO_MEM 1
#define CAMP_o 0
#define CAMP_x 1

typedef struct grid {
  // 如果还没还占领, 使用 -1
  // 否则是 0: o / 1: x
  int hold;
  int position;
} Grid;

// 初始化棋局
void init_game(Grid list[][SIZE]);

// 展示棋局
void show(Grid list[][SIZE]);

// 输入下一步
// camp 阵营, 0: o / 1: x
// 下棋成功返回 true
// 如果位置已经被下过 / 超出下棋范围 则返回 false
bool input_next_step(Grid list[][SIZE], int camp, int position);

// 判断胜利情况, -1: 未结束, 0: o胜利, 1: x胜利, 2:平局
int judge(Grid list[][SIZE]);

//bool destroy(Grid list[][SIZE]);

#endif //TTT_TTT_H
