#include "ex4pinball.h"

int COUNT = 0; //������ײ�������ͳ��
int main(void) {
  ��ʼ�����������
  ���뵯��ĸ���������num�У�������1~NUM֮��
  ���ö�̬�����ڴ�malloc()������num������Ľṹ���������ռ�
  //��ʼ��num������Ľṹ������
  initBall(ball, num);
  //���岢��ʼ����άͼ������cWin[HEIGHT][WIDTH]
  char cWin[HEIGHT][WIDTH];
  memset(cWin, ' ', HEIGHT*WIDTH); //��άͼ������ȫ����ʼ��Ϊ�ո��
  initCharPicture(cWin); //��άͼ������ı߽��ַ���ʼ��
  �����κ�ѭ��ֱ������ö�άͼ������cWin
  
  while(1){
    system("cls"); //ִ����������
    ����ö�άͼ������cWin
    redrawCWin(ball, num);
    Sleep(200);
    moveBall(ball, num);
    ���㵯��ײ�ش�������ʾ
  }
  �ͷ�������ڴ�ռ�
  fflush(stdin);
  getchar();
}
