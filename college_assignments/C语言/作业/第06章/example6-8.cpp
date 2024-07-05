#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( )
{
  float a, b, c;  
  float s, area;  

  printf("input the length of three edges of triangle: ");
  scanf("%f%f%f", &a, &b, &c);

  if (a <= 0 || b <= 0 || c <= 0)  
  {
	printf("the length of three edges of triangle is error!\n");
	exit(-1);
  }
  s = (a + b + c) / 2;
  s = s * (s - a) * (s - b) * (s - b);
  if (s < 0)
  {
	printf("the length of three edges of triangle is error!\n");
	exit(-1);
  }
  area = (float)sqrt(s);
  printf("area = %.2f\n", area);
  return 0;
}
