/* 各种系统库函数头文件的包含 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

/* 各种符号常量的定义 */
#define PI 3.14159265358979324
//动画图像的维度，上下纵向HEIGHT、左右横向WIDTH
#define HEIGHT 24
#define WIDTH 80

#define NUM 10 //弹球的最大数量

/* 各种复杂数据结构类型如结构体、共用体的定义 */
struct BALL {
	char body[2];//两个不同的字符，分别代表两个不同颜色的球
	int sel;     //当前球的颜色；0表示第一种颜色，1表示第二种颜色
	int wX;      //在二维数组中，球在x方向的实际显示位置（整数）
	int wY;      //在二维数组中，球在y方向的实际显示位置（整数）
	double X;    //球在x方向的精确位置（实数）
	double Y;    //球在y方向的精确位置（实数）
	double dX;   //球在x方向的速度（实数）
	double dY;   //球在y方向的速度（实数）
};

/* 所有自定义函数的声明 */
void initCharPicture(char cWin[][WIDTH]);
void redrawCWin(struct BALL ball[], int num);
void initBall(struct BALL ball[], int num);
int  moveBall(struct BALL ball[], int num);
double distBetweenBalls(struct BALL ball[], int i, int j);
void swap(double *x, double *y);
void color(const unsigned short color1);
