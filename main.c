#include <stdio.h>
#include "./include/ttt.h"

int main() {
  Grid list[SIZE][SIZE];
  init_game(list);

  show(list);

  char name[2] = { 'o', 'x' };
  // 首先 0: o 先下
  int camp = CAMP_o;
  int position;

  // 获取用户的输入数字, 判断能否下这一步棋
  while (true) {
    if (judge(list) != -1) {
      break;
    }
    printf("Now is [ %c ] turn \n", name[camp]);
    while ( !((scanf("%d", &position) == 1) && input_next_step(list, camp, position)) ) {
      printf("please input again !\n");
    }
    show(list);
    printf("\n");
    camp = !camp;
  }
  printf("!! WINNER is %c !! \n", name[!camp]);
  show(list);
//  destroy(list);

  return 0;
}

