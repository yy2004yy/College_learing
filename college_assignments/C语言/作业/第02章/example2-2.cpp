/* This is the second C program */
#include <stdio.h>  //Ԥ��������
	
int main( )  //�޲������޷���ֵ�ĺ���
{
  int x, y, z;  //�����������ͱ���x,y,z

  scanf("%d%d", &x, &y);  //�Ӽ����������������������ֱ𸳸�����x��y
  z = x + y;              //��x��y��ֵ��Ӹ���z
  printf("the sum of two integer is %d\n", z);  //�⺯������
  return 0;	
}
