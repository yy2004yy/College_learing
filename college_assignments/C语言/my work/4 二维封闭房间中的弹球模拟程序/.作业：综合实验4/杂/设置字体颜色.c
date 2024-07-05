#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
int main(void) {int i;
HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); //取得输出窗口的句柄(Handle to a WiNdoW)
SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY|FOREGROUND_RED); //设置字体高亮、红色
printf("Hello o o o ");
Sleep(2000); //延迟 2000 毫秒
SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY|FOREGROUND_GREEN);//设置字体高亮、绿色
printf("World!\n");
for(i=0; i<80; i++) printf("%d", i % 10); putchar('\n'); //显示一下窗口横向 X 坐标
for(i=2; i<24; i++) printf("%d\n", i); //显示一下窗口纵向 Y 坐标
/* 控制台窗口还可以直接使用数字来设置颜色，对应值：
0=黑色，1=蓝色，2=绿色，3=湖蓝色，4=红色，5=紫色，6=黄色，7=白色，8=灰色，9=亮蓝色
10=亮绿色 0xa，11=亮青色 0xb，12=亮红色 0xc，13=亮紫色 0xd，14=亮黄色 0xe，15=亮白色 0xf */
SetConsoleTextAttribute(consolehwnd, 14); //设置字体黑底亮黄色
//现在演示在窗口的任意指定坐标处显示字符或字符串
COORD coord; //注意 coord 的 X、Y 坐标和我们定义的二维字符数组 cWin[][]的行、列是反的
//输出窗口的最坐上角坐标为(0, 0)
coord.X = rand() % 80; //coord.X 是从左到右的横向坐标，coord.X = (ball+i)->wY
coord.Y = rand() % 24; //coord.Y 是从上到下的纵向坐标，coord.Y = (ball+i)->wX
printf("coord.X=%2d coord.Y=%2d\n", coord.X, coord.Y);
SetConsoleCursorPosition(consolehwnd, coord);
putchar('o');//占用一个字符宽度
SetConsoleTextAttribute(consolehwnd, 13); //设置字体黑底亮紫色
puts("●"); //这样的非标准 ASCII 符号输出占用两个字符宽度
SetConsoleTextAttribute(consolehwnd, 7); //切换回默认的黑底白色字体
}
