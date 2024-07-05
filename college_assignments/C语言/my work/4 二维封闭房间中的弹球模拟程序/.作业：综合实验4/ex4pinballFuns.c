#include "ex4pinball.h"
int times = 0;//times 全局 
/*
功能：将二维图像数组初始化为背景图模式。上下边界可以用-=*等，左右边界可以用|][等
最后一列全部赋值为'\n'，最后一个元素赋值为'\0'以方便输出。
*/
void initCharPicture(char cWin[HEIGHT][WIDTH])//24 80
{
	int i, j, k;
	for(i = 0, j = 0; j < 79; j++)
	cWin[i][j] = '-';
	cWin[i][j] = '\n';//cWin[0][80] = '\n';
	
	for(k = 1; k <= 22; k++)
	{		
		j = 0;
		cWin[k][j] = '!';
		for(j = 1; j < 78; j++)
		cWin[k][j] = ' ';
		cWin[k][j] = '!';
		cWin[k][j+1] = '\n';
	}
	
	for(i = 23, j = 0; j < 79; j++)
	cWin[i][j] = '-';
	cWin[i][j] = '\n';
	
	for(i = 0; i < 24; i++)
	for(j = 0; j < 80; j++)
		printf("%c", cWin[i][j]);
		//与下面输出字符串等价 
	//printf("%s", cWin);
}
 

//功能：根据num个弹球的最新位置，在屏幕上绘制出当前弹球位置的图像。
void redrawCWin(struct BALL ball[], int num)
{	
	int i;
	char cWin[24][80];

	for(i = 0; i < num; i++)
	{
		cWin[ball[i].wX][ball[i].wY] = ball[i].body[ball[i].sel];
	}

	for(i = 0; i < 24; i++)
	{
	printf("%s", cWin[i]);
	printf("\n");
	}
}

/*
功能：对num个弹球的数据进行初始化。
 */
void initBall(struct BALL ball[], int num)
{
	srand((unsigned)time(NULL));
	int i, k;
	
	for(i = 0; i < num; i++)
	{
		ball[i].body[1] = 'O';
		ball[i].body[2] = 'O';
		ball[i].sel = rand() % 2;
		ball[i].wX = (int)(ball[i].X);
		ball[i].wY = (int)(ball[i].Y);
		ball[i].X = rand() % 22+1;
		ball[i].Y = rand() % 77+1;
		k = rand() % 359;
		ball[i].dX = cos(k*PI/180);
		ball[i].dY = sin(k*PI/180);
	}
}

/*
功能：将num个弹球根据各自的速度移动一次。返回本次运动中弹球碰撞地面的次数。
注意：若弹球撞边界墙，则直接被弹回，速度分量需要改变方向（变相反数）；
特别的若弹球撞到地面（下面的墙），则被弹回的同时，发出弹回的声音。
若两个弹球相撞，则两个弹球都改变自身的颜色，以逆时针旋转90度改变速度的方向（直接设定而非物理规律）。
 */
int moveBall(struct BALL ball[], int num)
{
	int times = 0;
	int i, j, t;
	float dist;
	for(i = 0; i < num; i++)
	{
		ball[i].X = ball[i].X + ball[i].dX;
		ball[i].Y = ball[i].Y + ball[i].dY;
		ball[i].wX = (int)(ball[i].wX + 0.5);
		ball[i].wY = (int)(ball[i].wY + 0.5);
		
		if(ball[i].X < 0)
		{
			ball[i].dX = -ball[i].dX;
			ball[i].X = ball[i].X + ball[i].dX;
		}
		
		if(ball[i].X > 23)
		{
			ball[i].dX = -ball[i].dX;
			ball[i].X = ball[i].X + ball[i].dX;
			putchar('\7');//发出弹回的声音
			times++;//碰撞到地面 
		}
		
		
		if(ball[i].Y < 0 || ball[i].Y > 78)
		{
			ball[i].dY = -ball[i].dY;
			ball[i].Y = ball[i].Y + ball[i].dY;
		}
		
		for(i = 1; i < num; i++) 
			for(j = 0; j < num-i; j++)
			dist = sqrt((ball[i].X - ball[j].X) * (ball[i].X - ball[j].X) + (ball[i].Y - ball[j].Y) * (ball[i].Y - ball[j].Y)); 
			if (dist < 1)
			{
				t = ball[i].dY;
				ball[i].dY = -ball[i].dX;
				ball[i].dX = t;
			}
	}
	printf("撞击地面次数：%d", times);
	return (times);
}


/*
功能：计算弹球 i 和弹球 j 之间的距离的平方，用来判断是否相互碰撞。
不同的弹球之间的距离小于1.0时判定为相互碰撞 */

double distBetweenBalls(struct BALL ball[], int k, int i)//功能：计算弹球 k 和弹球 i 之间的距离。
 {
 	double dist;
 	dist = sqrt(pow((ball[k].X - ball[i].X),2)+pow((ball[k].Y-ball[i].Y),2));
 	return dist;
 }


 
 
/*
功能：指针法交换两个实数的值，或者写成交换整数
 */
void swap(double *x, double *y)
{ 
double temp = *x;
  *x = *y;
  *y = temp;
}

//颜色设置 
/*
void color(const unsigned short color1)
{       
	//仅限改变0-15的颜色;如果在0-15，那么实现对应的颜色。因为如果超过15，则默认白色。
	if (color1 >= 0 && color1 <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	//如果不在0-15的范围颜色，那么改为默认的颜色白色
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		//颜色对应值：
	//	0=黑色			      8=灰色　　
	//	1=蓝色			      9=淡蓝色                　　
	//	2=绿色			      10=淡绿色			0xa        　　
	　　//3=湖蓝色			  11=淡浅绿色		0xb　
	　//	4=红色			      12=淡红色			0xc　　
	　//	5=紫色			      13=淡紫色			0xd        　　
	　//	6=黄色			      14=淡黄色			0xe        　　
	//　	7=白色			      15=亮白色			0xf
		　　也可以把这些值设置成常量。
	
}*/
