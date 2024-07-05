//�˼�˷�����,�ֲ�����������
//2020.6.19
//������ 2019282129

#include<stdio.h>
#include<math.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

//����ĳ��Ϳ�
#define HIGN 24
#define WIDTH 80

//�ݶ�������֮��ľ����1ʱ��Ϊ��ײ
#define REACH 1   

#define PI 3.14159//Բ����
#define NUM 50	//����������
int COUNT = 0;

struct BALL {
	char body;//�����ַ�����ʾ����dos����̨Ӧ�е���̬
	int sel; //��ǰ�����ɫ��0��ʾ��һ����ɫ��1��ʾ�ڶ�����ɫ
	int wX; //�ڶ�ά�����У�����x�����ʵ����ʾλ�ã�������
	int wY; //�ڶ�ά�����У�����y�����ʵ����ʾλ�ã�������
	double X; //����x����ľ�ȷλ�ã�ʵ����
	double Y; //����y����ľ�ȷλ�ã�ʵ����
	double dX; //����x������ٶȣ�ʵ����
	double dY; //����y������ٶȣ�ʵ����
};

void Manage(struct BALL*, int);//ÿһ�����ڽ��е�һ�δ���
void print_pos(struct BALL*, int);//һ������������
void swap(double*, double*);//double���͵Ľ�������
void color(const unsigned short);//�趨��ɫ�ĺ���

int main() {
	srand(time(NULL));

	printf("��������ĸ�����");
	int num;//��ĸ���
	scanf("%d", &num);
	if (num > NUM)num = NUM;
	struct BALL *ball = (struct BALL*)malloc(sizeof(struct BALL) * num);
	if(ball == NULL)
	{
		printf("Insufficient memory available.");
		exit(-1);
	}

	for (int i = 0; i < num; i++) {
		(ball + i)->sel = rand() % 15 + 1;	//��ɫ
		(ball + i)->X = rand() % WIDTH + 1;	//x��ȷ����
		(ball + i)->Y = rand() % HIGN + 1;	//y��ȷ����

		//���жϿ��ƶ��࣬��ʵ��Ϊ�˷�ֹ��Щʱ���򱻡�ײ�����߽磬
		//�����ڳ���ƽ���ڱ߽�����˶��������������������޷���ʾ����
		if ((ball + i)->X < 1)							//�߽����
			(ball + i)->wX = 1;
		else if ((ball + i)->X >WIDTH)					//�߽����
			(ball + i)->wX = WIDTH;
		else 
			(ball + i)->wX = (int)((ball + i)->X+0.5);	//��������

		if ((ball + i)->Y < 1)							//�߽����
			(ball + i)->wY = 1;							
		else if ((ball + i)->Y > HIGN)					//�߽����
			(ball + i)->wY = HIGN;
		else
			(ball + i)->wY = (int)((ball + i)->Y+0.5);	//��������

		(ball + i)->body = 'o';//����Բ�ģ�����ֱ��ȫ����ΪСд��ĸo

		//�ٶȵĳ�ʼ������СΪһ����λ�������������
		double xita = rand() % 360;
		(ball + i)->dX = cos(PI * xita / 180);
		(ball + i)->dY = sin(PI * xita / 180);

	}

	
	while (TRUE)
	{
	//	system("CLS");
	//���������Ҳ��ô˷�����Ϊ���ŷ���������������С�

	/**************************************************************/
	HANDLE hOut;
    COORD pos={0,0};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut,pos);//�����ӡ���

    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut, &cci);
    cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cci);//���ع��

	/**************************************************************/

		print_pos(ball, num);

		Manage(ball, num);

		printf("��ش�����%d", COUNT);
		Sleep(25);//����25����


	}

	
	free(ball);			//��ʵ�����Ƕ����
	return 1;			//������򲻿��ܻ��������ķ���ֵ0������������أ���һ���Ƿ�0��
}

//��ʾ����̨��ĳ���ʵ��λ��
void print_pos(struct BALL* p, int num) {
	//�ϱ߽�
	for (int i = 0; i < WIDTH + 2; i++)
		putchar('*');
	putchar('\n');

	//�м䲿��
	for (int i = 1; i <= HIGN; i++) {
		putchar('|');
		
		for (int j = 1; j <= WIDTH; j++) {
			short flag = 1;
			for (int k = 0; k < num; k++) {
			//���ѭ����Ŀ���ǣ���һ���Ƿ��ڸ�λ������һ������������
			//�����һ��������break��
			//���������ڵ�һ������Ѿ�break���ˡ���һ˲��������Ӱ�������޷��������
			//���������Ʋ����۲���࣬���ǲ������������ܵ����ұ߽类��ײ������
				if ((p + k)->wX == j && (p + k)->wY == i) {
					color((p + k)->sel);
					putchar((p + k)->body);
					color(7);
					flag = 0;
					break;
				}

			}
			if (flag)
				putchar(' ');
		}

		putchar('|');
		putchar('\n');
	}
	//�±߽�
	for (int i = 0; i < WIDTH + 2; i++)
		putchar('*');
	putchar('\n');

}

void Manage(struct BALL* p, int num) {

	//�����������ֱ�ӽ�����Ϊ�ʵ㣬���ö�����ײ��
	//����������֮�����ײ�������������������һ���ģ���������ʧ�������غ㣬���ٶȽ�����
	for (int i = 1; i < num; i++) 
		for(int j=0;j<num-i;j++)
			if (pow((p + i)->X - (p + j)->X, 2) + pow((p + i)->Y - (p + j)->Y, 2) <= pow(REACH,2))
			{
				swap(&(p + i)->dX, &(p + j)->dX);
				swap(&(p + i)->dY, &(p + j)->dY);
			}

	//���²���ָ��ķ�ʽ���Ա㴦������
	for (int i = 0; i < num; i++){

		//�����������ڵ����
		if ((p + i)->X <= 1 || (p + i)->X >= WIDTH) {
			(p + i)->dX = -(p + i)->dX;
		}

		//�����Ϸ����ڵ����
		if ((p + i)->Y <= 1) {
			(p + i)->dY = -(p + i)->dY;
			
		}

		//�����·����ڵ����
		if ((p + i)->Y >= HIGN) {
			(p + i)->dY = -(p + i)->dY;
			putchar('\7');//��������
			COUNT++;//��¼��ش���
		}

		//���λ���ڴ˷����ı���,�ı���Ϊ�ٶȳ���һ��ʱ�䵥λ 
		(p + i)->X += (p + i)->dX;
		(p + i)->Y += (p + i)->dY;
	
		
		//�����ʾλ����ʵ��λ����Ӧ�ı�
		if ((p + i)->X < 1)
			(p + i)->wX = 1;
		else if ((p + i)->X > WIDTH)
			(p + i)->wX = WIDTH;
		else
			(p + i)->wX = (int)((p + i)->X + 0.5);

		if ((p + i)->Y < 1)
			(p + i)->wY = 1;
		else if ((p + i)->Y > HIGN)
			(p + i)->wY = HIGN;
		else
			(p + i)->wY = (int)((p + i)->Y + 0.5);
	}
}


void swap(double* x, double* y) {
	double temp = *x;
	*x = *y;
	*y = temp;
}



void color(const unsigned short color1)
{       
	/*���޸ı�0-15����ɫ;�����0-15����ôʵ�ֶ�Ӧ����ɫ����Ϊ�������15����Ĭ�ϰ�ɫ��*/
	if (color1 >= 0 && color1 <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	/*�������0-15�ķ�Χ��ɫ����ô��ΪĬ�ϵ���ɫ��ɫ��*/
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		/*��ɫ��Ӧֵ��
			0=��ɫ			      8=��ɫ����
			1=��ɫ			      9=����ɫ                ����
			2=��ɫ			      10=����ɫ			0xa        ����
		����	3=����ɫ			      11=��ǳ��ɫ		0xb��
		����	4=��ɫ			      12=����ɫ			0xc����
		����	5=��ɫ			      13=����ɫ			0xd        ����
		����	6=��ɫ			      14=����ɫ			0xe        ����
		����	7=��ɫ			      15=����ɫ			0xf
		����Ҳ���԰���Щֵ���óɳ�����
		*/
}

