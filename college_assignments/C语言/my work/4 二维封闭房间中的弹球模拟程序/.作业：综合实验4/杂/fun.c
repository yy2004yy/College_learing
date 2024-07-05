
 
 
 //����
 
 
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
 
int randX(void)//���ܣ�����һ�����������Ϊ����ĳ�ʼ��λ�á�
{
	return (1+rand()%22);
}
 
int randY(void)//���ܣ�����һ�����������Ϊ����ĳ�ʼ��λ�á�
{
	return (1+rand()%77);
}
 
int randA(void)//���ܣ�����0-359֮���һ�����������Ϊ������˶�����
{
	return (rand()%359);
}
 
double distBetweenBalls(struct BALL ball[], int k, int i)//���ܣ����㵯�� k �͵��� i ֮��ľ��롣
 {
 	double dist;
 	dist = sqrt(pow((ball[k].X - ball[i].X),2)+pow((ball[k].Y-ball[i].Y),2));
 	return dist;
 }
 
 void initCharPicture(char cWin[24][80])//���ܣ���ͼ�������ʼ��Ϊ����ͼģʽ��
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
 
 void delay(int nTime)//���ܣ���ʱһ��ʱ�䡣���У����� nTime ������ʱ�ĳ��ȡ�
 {
 	int i,j;
 	for(i=0;i<nTime;i++)
 	{
	 for(j=0;j<1100000;j++);
						
	 }
 }
 
 int moveBall(struct BALL ball[], int num, int p)//���ܣ���num��������ݸ��Ե��ٶ��ƶ�һ�Ρ����ر����˶��е�����ײ����Ĵ�����������ײǽ���򱻵��أ��ر�������ײ�����棨�����ǽ�����򱻵��ص�ͬʱ���������ص�������������������ײ�����������򶼸ı��������ɫ���ı��ٶȵķ���
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
 
 void redrawCWin(struct BALL ball[], int num)//���ܣ�����num�����������λ�ã�����Ļ�ϻ��Ƴ���ǰ����λ�õ�ͼ��
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
