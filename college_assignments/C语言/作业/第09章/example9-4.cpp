#include <stdio.h>

int main()
{
  short int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
  short int (*p)[3];
  short int i, j;

  p = a;   // pָ���ά����a�ĵ�һ���е�ַ 
  for (i = 0; i < 2; i++)   //����i��������
  {
    for (j = 0; j < 3; j++)  //����j��������
      printf("a[%d][%d] = %d  ", i, j, p[i][j]);  //��ʾÿ������Ԫ�ص�ֵ
    printf("\n");   //�����ÿһ��Ԫ���������
  }
  
  p++;   // pָ���ά����a�ĵڶ����е�ַ
  for (j = 0; j < 3; j++) 
    printf("%d  ", p[0][j]);   //��ʾ�����еڶ��е�Ԫ��ֵ
  return 0;
}

