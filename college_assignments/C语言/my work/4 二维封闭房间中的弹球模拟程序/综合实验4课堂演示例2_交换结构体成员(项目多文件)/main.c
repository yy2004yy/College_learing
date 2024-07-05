#include "EXP4_structMultifile.h"  //项目的其它.c文件中都包含上这个头文件

/*
  main()的文件中只负责变量定义、与用户的交互(数据输入输出等)、
  以及各种功能自定义函数的调用
*/
int main() {
  struct Person leader[N]={ {"Li", 3},
                            {"Zhang",10},
                            {"Sun",0}};
  if (leader[0].points < leader[1].points)
    swap(&leader[0].points, &leader[1].points);
  printf("Li:%d, Zhang: %d\n", leader[0].points, leader[1].points);
  return 0;
}
