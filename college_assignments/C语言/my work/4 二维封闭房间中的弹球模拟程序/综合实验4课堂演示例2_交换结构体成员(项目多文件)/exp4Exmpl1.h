/**
 * @file exp4Exmpl1.h 
 * @brief: �ۺ�ʵ��4��1_�����ṹ���Ա(��Ŀ)��ͷ�ļ�
 **/
//�⺯��ͷ�ļ�
#include <stdio.h>
#include <string.h>

//�곣����ȫ�ֱ�����
#define N 3

//�ṹ�塢����ȸ����������͵Ķ���
struct Person{
  char name[20];
  int points; 
};

//�Զ��庯��������
void swap(int *p1, int *p2);
