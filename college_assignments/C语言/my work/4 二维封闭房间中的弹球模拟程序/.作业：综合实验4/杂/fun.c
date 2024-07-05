
 
 
 //函数
 
 
#include "head.h"
 
 
 
void initBall(struct BALL ball[], int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		ball[i].body[0]='*';
		ball[i].body[1]='0';
		ball[i].sel = randsel();
		ball[i].X = randX();
		ball[i].Y = randY();
		ball[i].wX = (int)(ball[i].X + 0.5);
		ball[i].wY = (int)(ball[i].Y + 0.5);
		ball[i].dX = cos((PI* randA() )/180);
		ball[i].dY = sin((PI* randA() )/180);
 
	}
	
}
 
int randsel(void)
{
	int s;
	s = rand() % 2;
	return s;
}
 
int randX(void)//功能：生成一个随机数，作为弹球的初始行位置。
{
	return (1+rand()%22);
}
 
int randY(void)//功能：生成一个随机数，作为弹球的初始列位置。
{
	return (1+rand()%77);
}
 
int randA(void)//功能：生成0-359之间的一个随机数，作为弹球的运动方向。
{
	return (rand()%359);
}
 
double distBetweenBalls(struct BALL ball[], int k, int i)//功能：计算弹球 k 和弹球 i 之间的距离。
 {
 	double dist;
 	dist = sqrt(pow((ball[k].X - ball[i].X),2)+pow((ball[k].Y-ball[i].Y),2));
 	return dist;
 }
 
 void initCharPicture(char cWin[24][80])//功能：将图像数组初始化为背景图模式。
 {
 	int i,j;
	 for(i=0;i<24;i++)
	 {
	 	for(j=0;j<79;j++)
	 	{
	 		cWin[i][j]=' ';
		 }
	 }
	 for(i=0;i<24;i++)
	 cWin[i][79]='\0';
 }
 
 void delay(int nTime)//功能：延时一段时间。其中，参数 nTime 调节延时的长度。
 {
 	int i,j;
 	for(i=0;i<nTime;i++)
 	{
	 for(j=0;j<1100000;j++);
						
	 }
 }
 
 int moveBall(struct BALL ball[], int num, int p)//功能：将num个弹球根据各自的速度移动一次。返回本次运动中弹球碰撞地面的次数。若弹球撞墙，则被弹回；特别，若弹球撞到地面（下面的墙），则被弹回的同时，发出弹回的声音。若两个弹球相撞，则两个弹球都改变自身的颜色，改变速度的方向。
 {
 		int i;
		p=0;
	
		for(i=0;i<num;i++)
		{
		ball[i].X += ball[i].dX ;
		ball[i].Y += ball[i].dY ;
		}
		
		for (i = 0; i < num; i++)
	{
		int j;
		
		if(ball[i].X>23)
		{
			putchar('\7');
			p++;
		}
		if(ball[i].X<0||ball[i].X>23)
		{
			ball[i].dX = -ball[i].dX;
			ball[i].X += ball[i].dX ;
 
 
		}
		
		else if(ball[i].Y<0||ball[i].Y>79)
		{
			ball[i].dY = -ball[i].dY;
			ball[i].Y += ball[i].dY;
 
 
		}
		else
		{
			ball[i].wX = (int)(ball[i].X + 0.5);
				ball[i].wY = (int)(ball[i].Y + 0.5);
		}
		
		for(j=i+1;j<num;j++)
		{
			double dist=distBetweenBalls(ball, i, j);
			if(dist<1)
			{
				double t;
				t=ball[i].dX;
				ball[i].dX=ball[i].dY;
				ball[i].dY=t;
				if(ball[i].sel==0)
					ball[i].sel=1;
				else
					ball[i].sel=0;
 
				t=ball[j].dX;
				ball[j].dX=ball[j].dY;
				ball[j].dY=t;
				if(ball[i].sel==0)
					ball[j].sel=1;
				else
					ball[j].sel=0;
 
			}
				
		}
			ball[i].wX = (int)(ball[i].X + 0.5);
			ball[i].wY = (int)(ball[i].Y + 0.5);
 
				
	}
 
		return p; 
}
 
 void redrawCWin(struct BALL ball[], int num)//功能：根据num个弹球的最新位置，在屏幕上绘制出当前弹球位置的图像。
 {
 	int i;
 	char cWin[24][80];
	 initCharPicture(cWin);
	 for (i=0;i<num;i++)
	 {
	 	cWin[ball[i].wX][ball[i].wY]= ball[i].body[ball[i].sel];		
	 }
	 
	 for (i=0;i<24;i++)
	 {
 
	  	printf("%s",cWin[i]);
		printf("\n");
			
	
	  }
	
 
	 
	 
 }
