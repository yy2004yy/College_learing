#include "ex4pinball.h"

/*
功能：将二维图像数组初始化为背景图模式。上下边界可以用-=*等，左右边界可以用|][等
最后一列全部赋值为'\n'，最后一个元素赋值为'\0'以方便输出。
 */
void initCharPicture(char cWin[][WIDTH])
{
}

/*
功能：根据num个弹球的最新位置，在屏幕上绘制出当前弹球位置的图像。
 */
void redrawCWin(struct BALL ball[], int num)
{
}

/*
功能：对num个弹球的数据进行初始化。
 */
void initBall(struct BALL ball[], int num)
{
}

/*
功能：将num个弹球根据各自的速度移动一次。返回本次运动中弹球碰撞地面的次数。
注意：若弹球撞边界墙，则直接被弹回，速度分量需要改变方向（变相反数）；
特别的若弹球撞到地面（下面的墙），则被弹回的同时，发出弹回的声音。
若两个弹球相撞，则两个弹球都改变自身的颜色，以逆时针旋转90度改变速度的方向（直接设定而非物理规律）。
 */
int moveBall(struct BALL ball[], int num)
{
}


/*
功能：计算弹球 i 和弹球 j 之间的距离的平方，用来判断是否相互碰撞。
不同的弹球之间的距离小于1.0时判定为相互碰撞
 */
double distBetweenBalls(struct BALL ball[], int i, int j)
{
}

/*
功能：指针法交换两个实数的值，或者写成交换整数
 */
void swap(double *x, double *y)
{ double temp = *x;
  *x = *y;
  *y = temp;
}
