/* ����ϵͳ�⺯��ͷ�ļ��İ��� */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

/* ���ַ��ų����Ķ��� */
#define PI 3.14159265358979324
//����ͼ���ά�ȣ���������HEIGHT�����Һ���WIDTH
#define HEIGHT 24
#define WIDTH 80

#define NUM 10 //������������

/* ���ָ������ݽṹ������ṹ�塢������Ķ��� */
struct BALL {
	char body[2];//������ͬ���ַ����ֱ����������ͬ��ɫ����
	int sel;     //��ǰ�����ɫ��0��ʾ��һ����ɫ��1��ʾ�ڶ�����ɫ
	int wX;      //�ڶ�ά�����У�����x�����ʵ����ʾλ�ã�������
	int wY;      //�ڶ�ά�����У�����y�����ʵ����ʾλ�ã�������
	double X;    //����x����ľ�ȷλ�ã�ʵ����
	double Y;    //����y����ľ�ȷλ�ã�ʵ����
	double dX;   //����x������ٶȣ�ʵ����
	double dY;   //����y������ٶȣ�ʵ����
};

/* �����Զ��庯�������� */
void initCharPicture(char cWin[][WIDTH]);
void redrawCWin(struct BALL ball[], int num);
void initBall(struct BALL ball[], int num);
int  moveBall(struct BALL ball[], int num);
double distBetweenBalls(struct BALL ball[], int i, int j);
void swap(double *x, double *y);
void color(const unsigned short color1);
