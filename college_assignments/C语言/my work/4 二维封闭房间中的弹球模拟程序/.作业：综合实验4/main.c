#include "ex4pinball.h"
int times = 0; //������ײ�������ͳ��(ȫ�ֱ���)
int main()
{
	int num;//����ĸ��� num 
	//srand((unsigned)time(NULL));//��ʼ�����������
	printf("��������ĸ�����num����"); 
	scanf("%d", &num);//���뵯��ĸ���������num�У�������1~NUM֮��
	struct BALL ball[num];
	
	if (num > NUM) num = NUM;
	if (num <= 1) num = 1;
	struct BALL *b = (struct BALL*)malloc(sizeof(struct BALL) * num);
	/* ���û�����ĵ������С��1�������õ�������Ϊ 1�����û�����ĵ���������� NUM ʱ�������õ������ΪNUM�����û�����ĵ�������� 1 �� NUM ֮�䣬�������Ϊ�û�����ĸ����� */ 
	
	if(b == NULL)
	{
		printf("Insufficient memory available.");
		exit(-1);
	}//���ö�̬�����ڴ�malloc()������num������Ľṹ���������ռ�
	
	//��ʼ��num������Ľṹ������
	initBall(ball, num);
	
	//���岢��ʼ����άͼ������cWin[HEIGHT][WIDTH]
	char cWin[HEIGHT][WIDTH];
	//memset(cWin, ' ', HEIGHT*WIDTH); //��άͼ������ȫ����ʼ��Ϊ�ո��
	initCharPicture(cWin); //��άͼ������ı߽��ַ���ʼ��
	//�����κ�ѭ��ֱ������ö�άͼ������cWin
	
	while(1)
	{
    system("CLS"); //ִ����������
	initCharPicture(cWin);
    redrawCWin(ball, num);//���С�� �Լ����� 
    Sleep(50);//�ӳ�2�� 
    moveBall(ball, num);//����С������ĸı䣬���㵯��ײ�ش�������ʾ
	}
	
	//�ͷ�������ڴ�ռ�*/
	free(b);
	fflush(stdin);
	getchar();
	
	return 0;
}
