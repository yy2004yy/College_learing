#include "ex4pinball.h"

int COUNT = 0; //弹球碰撞地面次数统计
int main(void) {
  初始化随机数种子
  输入弹球的个数保存在num中，数量在1~NUM之间
  利用动态分配内存malloc()函数给num个弹球的结构体数组分配空间
  //初始化num个弹球的结构体数组
  initBall(ball, num);
  //定义并初始化二维图像数组cWin[HEIGHT][WIDTH]
  char cWin[HEIGHT][WIDTH];
  memset(cWin, ' ', HEIGHT*WIDTH); //二维图像数组全部初始化为空格符
  initCharPicture(cWin); //二维图像数组的边界字符初始化
  无需任何循环直接输出该二维图像数组cWin
  
  while(1){
    system("cls"); //执行清屏命令
    输出该二维图像数组cWin
    redrawCWin(ball, num);
    Sleep(200);
    moveBall(ball, num);
    计算弹球撞地次数并显示
  }
  释放申请的内存空间
  fflush(stdin);
  getchar();
}
