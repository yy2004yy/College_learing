#include <stdio.h>

int main()
{
  int x, b0, b1, b2;         //��������

  printf("please input an integer x: ");  //��ʾ�û�����һ������
  scanf("%d", &x);           //����һ������

  b2 = x / 100;              //�����������������λ
  b1 = (x - b2 * 100) / 10;  //�����м�λ
  b0 = x % 10;               //�����������������λ

  printf("bit2 = %d, bit1 = %d, bit0 = %d\n", b2, b1, b0);  //������
  return 0;
}   
