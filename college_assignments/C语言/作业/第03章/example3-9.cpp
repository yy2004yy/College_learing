#include  <stdio.h>

int main()
{
  short a = 0xf245 , b, c;

  b = a << 8 ;     //将a的低8位移到高8位赋值给b，b的值为0x4500
  c = a >> 8 ;     //将a的高8位移到低8位赋值给c，c的值为0xfff2
  c = c & 0x00ff;  //将c的高8位清0后赋值给c，c的值为0x00f2
  a = b + c;       //将b和c的值相加赋值给a，a的值为0x450f2
  printf("a = %x",a);
  return 0;
}
