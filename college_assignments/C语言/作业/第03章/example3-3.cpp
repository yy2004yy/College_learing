#include <stdio.h>
	
int main (  )
{
  float a;             //定义float型变量a
  double b, c;         //定义double型变量b和c
	
  a = 123.456789;      //对变量a赋值为123.456789
  b = a;               //将变量a赋给变量b
  c = 123.456789;      //对变量c赋值为123.456789
  printf("a = %f   b = %lf   c = %lf\n", a, b, c);
  return 0;
}
