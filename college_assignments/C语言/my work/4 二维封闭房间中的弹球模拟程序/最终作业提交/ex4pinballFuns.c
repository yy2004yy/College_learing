#include "ex4pinball.h"

int times = 0;//times ȫ�� 
/*
���ܣ�����άͼ�������ʼ��Ϊ����ͼģʽ�����±߽������-=*�ȣ����ұ߽������|][��
���һ��ȫ����ֵΪ'\n'�����һ��Ԫ�ظ�ֵΪ'\0'�Է��������
*/
void initCharPicture(char cWin[HEIGHT][WIDTH])//24�� 80�� 
{

	int i, j, k;
	for(i = 0, j = 0; j < 79; j++)
	cWin[i][j] = '-';
	cWin[i][j] = '\n';
	
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
	cWin[i][j] = '\0';
	
//	for(i = 0; i < 24; i++)
//	for(j = 0; j < 80; j++)
//		printf("%c", cWin[i][j]);
		//����������ַ����ȼ� 
	//printf("%s", cWin);
}
 

//���ܣ�����num�����������λ�ã�����Ļ�ϻ��Ƴ���ǰ����λ�õ�ͼ��
//!���԰�cwin��Ϊ�βΣ������ں����ڶ��� 
void redrawCWin(char cWin[HEIGHT][WIDTH], struct BALL ball[], int num)
{	
	int i, j, k;
 
	for(i = 0; i < num; i++)
	{
		cWin[ball[i].wX][ball[i].wY] = ball[i].body[ball[i].sel]; 
	}
	
	srand((unsigned)time(NULL));

	
	for(i = 0; i < HEIGHT; i++)
	{
		for(j = 0; j < WIDTH; j++)
		{
			
			if(cWin[i][j] == 'o')
			{
			
				for(k = 0; k < num; k++)
				{
					if(ball[k].wX == i && ball[k].wY == j)
					{
						HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
						SetConsoleTextAttribute(consolehwnd, ball[k].color);//������ɫ 
						printf("%c", cWin[i][j]);
						SetConsoleTextAttribute(consolehwnd, 7);
						break;
					}
				}
			}
			else
			printf("%c", cWin[i][j]);
		}
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
		ball[i].body[0] = 'o';
		ball[i].body[1] = 'o';
		ball[i].sel = rand() % 2;
		ball[i].color = rand() % 16+1;//����1�Ǻ�ɫ ������ֱ�Ӵ�1��ʼ 
		//rand()���ص���������Ҫ�ȸ�wX wY�ȶ��� 
		ball[i].wX = rand() % 22+1;
		ball[i].wY = rand() % 77+1;
		ball[i].X = (double)(ball[i].wX);
		ball[i].Y = (double)(ball[i].wY);
	
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
	int i, j, t;
	float dist;
	for(i = 0; i < num; i++)
	{
		ball[i].X = ball[i].X + ball[i].dX;
		ball[i].Y = ball[i].Y + ball[i].dY;
		//ײǽ֮���ٶ���wY��wX 

		if(ball[i].X < 1)
		{
			ball[i].dX = -ball[i].dX;
			ball[i].X = ball[i].X + ball[i].dX;
		}
		
		if(ball[i].X > 22)
		{
			ball[i].dX = -ball[i].dX;
			ball[i].X = ball[i].X + ball[i].dX;
			putchar('\7');//�������ص�����
			times++;//��ײ������ 
		}
		
		if(ball[i].Y < 1 || ball[i].Y > 77)
		{
			ball[i].dY = -ball[i].dY;
			ball[i].Y = ball[i].Y + ball[i].dY;
		}

		ball[i].wX = (int)(ball[i].X + 0.5);
		ball[i].wY = (int)(ball[i].Y + 0.5);
		
	}
	
	for(i = 0; i < num; i++)
	{
		ball[i].X = ball[i].X + ball[i].dX;
		ball[i].Y = ball[i].Y + ball[i].dY;
		
		for(j = i + 1; j < num; j++)
		{
			dist = sqrt( pow((ball[i].X - ball[j].X), 2) + pow((ball[i].Y - ball[j].Y),2) ); 
			if (dist < 0.1)//����֮���ֱ��С��0.1 (�����1�Ļ��������ס�� 
			{
				t = ball[i].dY;
				ball[i].dY = -ball[i].dX;
				ball[i].dX = t;
				
				if(ball[i].sel==0)
					ball[i].sel=1;
				else
					ball[i].sel=0;
				
				t = ball[j].dY;
				ball[j].dY = -ball[j].dX;
				ball[j].dX = t;
				
				if(ball[j].sel==0)
					ball[j].sel=1;
				else
					ball[j].sel=0;
			} 
			
		}
		
		ball[i].wX = (int)(ball[i].X + 0.5);
		ball[i].wY = (int)(ball[i].Y + 0.5);
		
	}
	printf("\nײ�����������%d\n", times);
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

//�������ع�꺯��
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = FALSE;    
	cursor.dwSize = sizeof(cursor);    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
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
