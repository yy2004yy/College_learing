#include  <stdio.h>

int main()
{
  short a = 0xf245 , b, c;

  b = a << 8 ;     //��a�ĵ�8λ�Ƶ���8λ��ֵ��b��b��ֵΪ0x4500
  c = a >> 8 ;     //��a�ĸ�8λ�Ƶ���8λ��ֵ��c��c��ֵΪ0xfff2
  c = c & 0x00ff;  //��c�ĸ�8λ��0��ֵ��c��c��ֵΪ0x00f2
  a = b + c;       //��b��c��ֵ��Ӹ�ֵ��a��a��ֵΪ0x450f2
  printf("a = %x",a);
  return 0;
}
