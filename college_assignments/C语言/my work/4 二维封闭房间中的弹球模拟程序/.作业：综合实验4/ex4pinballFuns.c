#include "ex4pinball.h"
int times = 0;//times ȫ�� 
/*
���ܣ�����άͼ�������ʼ��Ϊ����ͼģʽ�����±߽������-=*�ȣ����ұ߽������|][��
���һ��ȫ����ֵΪ'\n'�����һ��Ԫ�ظ�ֵΪ'\0'�Է��������
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
		//����������ַ����ȼ� 
	//printf("%s", cWin);
}
 

//���ܣ�����num�����������λ�ã�����Ļ�ϻ��Ƴ���ǰ����λ�õ�ͼ��
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
���ܣ���num����������ݽ��г�ʼ����
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
���ܣ���num��������ݸ��Ե��ٶ��ƶ�һ�Ρ����ر����˶��е�����ײ����Ĵ�����
ע�⣺������ײ�߽�ǽ����ֱ�ӱ����أ��ٶȷ�����Ҫ�ı䷽�򣨱��෴������
�ر��������ײ�����棨�����ǽ�����򱻵��ص�ͬʱ���������ص�������
������������ײ�����������򶼸ı��������ɫ������ʱ����ת90�ȸı��ٶȵķ���ֱ���趨����������ɣ���
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
			putchar('\7');//�������ص�����
			times++;//��ײ������ 
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
	printf("ײ�����������%d", times);
	return (times);
}


/*
���ܣ����㵯�� i �͵��� j ֮��ľ����ƽ���������ж��Ƿ��໥��ײ��
��ͬ�ĵ���֮��ľ���С��1.0ʱ�ж�Ϊ�໥��ײ */

double distBetweenBalls(struct BALL ball[], int k, int i)//���ܣ����㵯�� k �͵��� i ֮��ľ��롣
 {
 	double dist;
 	dist = sqrt(pow((ball[k].X - ball[i].X),2)+pow((ball[k].Y-ball[i].Y),2));
 	return dist;
 }


 
 
/*
���ܣ�ָ�뷨��������ʵ����ֵ������д�ɽ�������
 */
void swap(double *x, double *y)
{ 
double temp = *x;
  *x = *y;
  *y = temp;
}

//��ɫ���� 
/*
void color(const unsigned short color1)
{       
	//���޸ı�0-15����ɫ;�����0-15����ôʵ�ֶ�Ӧ����ɫ����Ϊ�������15����Ĭ�ϰ�ɫ��
	if (color1 >= 0 && color1 <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	//�������0-15�ķ�Χ��ɫ����ô��ΪĬ�ϵ���ɫ��ɫ
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		//��ɫ��Ӧֵ��
	//	0=��ɫ			      8=��ɫ����
	//	1=��ɫ			      9=����ɫ                ����
	//	2=��ɫ			      10=����ɫ			0xa        ����
	����//3=����ɫ			  11=��ǳ��ɫ		0xb��
	��//	4=��ɫ			      12=����ɫ			0xc����
	��//	5=��ɫ			      13=����ɫ			0xd        ����
	��//	6=��ɫ			      14=����ɫ			0xe        ����
	//��	7=��ɫ			      15=����ɫ			0xf
		����Ҳ���԰���Щֵ���óɳ�����
	
}*/
