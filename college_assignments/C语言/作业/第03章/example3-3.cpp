#include <stdio.h>
	
int main (  )
{
  float a;             //����float�ͱ���a
  double b, c;         //����double�ͱ���b��c
	
  a = 123.456789;      //�Ա���a��ֵΪ123.456789
  b = a;               //������a��������b
  c = 123.456789;      //�Ա���c��ֵΪ123.456789
  printf("a = %f   b = %lf   c = %lf\n", a, b, c);
  return 0;
}
