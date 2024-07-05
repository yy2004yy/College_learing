#include  <stdio.h>
	
int main()
{
  float a, b,c;

  a = 7 / 2;         //计算7/2得int型值3，因此a的值为3.0
  b = 7 / 2 * 1.0;   //计算7/2得int型值3，再与1.0相乘，因此b的值为3.0
  c = 1.0 * 7 / 2;   //先计算1.0*7得double型的结果7.0，然后再计算7.0/2，因此C的值是3.5
  printf("a = %f, b = %f, c = %f",a,b,c);
  return 0;
}
