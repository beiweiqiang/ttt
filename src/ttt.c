#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/ttt.h"

// 初始化棋局
void init_game(Grid list[SIZE][SIZE]) {

  int pos = 1;
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      list[i][j].hold = -1;
      list[i][j].position = pos;
      pos++;
    }
  }
}

// 展示棋局
void show(Grid list[SIZE][SIZE]) {
  Grid tmp;
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      tmp = list[i][j];
      if (tmp.hold == -1) {
        printf("%d", tmp.position);
      } else {
        printf("%c", tmp.hold == CAMP_o ? 'o' : 'x');
      }
      printf(" ");
    }
    printf("\n");
  }
}

// 输入下一步
// camp 阵营, 0: o / 1: x
// 下棋成功返回 true
// 如果位置已经被下过 / 超出下棋范围 则返回 false
bool input_next_step(Grid list[][SIZE], int camp, int position) {
  Grid *tmp;
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      tmp = &list[i][j];
      if (tmp->position == position && tmp->hold == -1) {
        tmp->hold = camp;
        return true;
      }
    }
  }
  return false;
}

// 判断胜利情况, -1: 未结束, 0: o胜利, 1: x胜利, 2:平局
int judge(Grid list[][SIZE]) {
  Grid * tmp;
  for (int i = 0; i < SIZE; ++i) {
    tmp = list[i];
    bool flag = true;
    int start = 0;
    int step = 1;
    while (start < SIZE - 1) {
      flag =
        flag &&
        ( (tmp + start)->hold == (tmp + start + step)->hold ) &&
        (tmp + start)->hold != -1;
      start += step;
    }
    if (flag) {
      return tmp->hold;
    }
  }

  for (int j = 0; j < SIZE; ++j) {
    tmp = list[j];
    bool flag = true;
    int start = 0;
    int step = SIZE;
    while (start < 3 * SIZE) {
      flag =
        flag &&
        ( (tmp + start)->hold == (tmp + start + step)->hold ) &&
        (tmp + start)->hold != -1;
      start += step;
    }
    if (flag) {
      return tmp->hold;
    }
  }


  {
    tmp = list[0];
    bool flag = true;
    int start = 0;
    int step = SIZE + 1;
    while (start < 3 * SIZE) {
      flag =
        flag &&
        ( (tmp + start)->hold == (tmp + start + step)->hold ) &&
        (tmp + start)->hold != -1;
      start += step;
    }
    if (flag) {
      return tmp->hold;
    }
  }

  {
    tmp = list[SIZE - 1];
    bool flag = true;
    int start = 0;
    int step = SIZE - 1;
    while (start <= 2 * SIZE + 1) {
      flag =
        flag &&
        ( (tmp + start)->hold == (tmp + start + step)->hold ) &&
        (tmp + start)->hold != -1;
      start += step;
    }
    if (flag) {
      return tmp->hold;
    }
  }

  return -1;
}

//bool destroy(Grid * list[SIZE]) {}

