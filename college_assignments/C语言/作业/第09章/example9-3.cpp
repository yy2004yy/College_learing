#include  <stdio.h>
	
int main()
{
  short int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
  short int i, j,*p;

  p = &a[0][0];   //Ҳ��д��p = a[0];  pָ���ά����a�ĵ�һ����Ԫ 
  for(i = 0; i < 2; i++)   //����i��������
  {
    for(j = 0; j < 3; j++)  //����j��������
      printf("a[%d][%d] = %d  ", i, j, *(p + i*3 + j));  //��ʾÿ������Ԫ�ص�ֵ
    printf("\n");   //�����ÿһ��Ԫ���������
  } 
  return 0;
}
