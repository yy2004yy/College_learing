/**
 * @file EXP4_structMultifile.h
 * @brief: �ۺ�ʵ��4������ʾ��2_�����ṹ���Ա(��Ŀ���ļ�)��ͷ�ļ�
 **/
//�⺯��ͷ�ļ�
#include <stdio.h>
#include <string.h>

//�곣����
#define N 3

//�ṹ�塢����ȸ����������͵Ķ���
struct Person{
  char name[20];
  int points;
};

//�Զ��庯��������
void swap(int *p1, int *p2);