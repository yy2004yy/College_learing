#include "ex4pinball.h"
int COUNT = 0; //������ײ�������ͳ��
int main()
{
	int num;//����ĸ��� num 
//	srand((unsigned)time(NULL));//��ʼ�����������
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
	printf("%s", cWin);
	
	while(1)
	{
    system("CLS"); //ִ����������
    HideCursor();//���ع�� 
	initCharPicture(cWin);
    redrawCWin(cWin, ball, num);//���С�� �Լ�����
	moveBall(ball, num);//����С������ĸı䣬���㵯��ײ�ش�������ʾ
	Sleep(30);//�ӳ�50����
	}
	
	//�ͷ�������ڴ�ռ�*/
	free(b);
	fflush(stdin);
	getchar();
	
	return 0;
}
