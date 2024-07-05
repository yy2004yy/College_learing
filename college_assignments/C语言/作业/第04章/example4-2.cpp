#include <stdio.h>
	
int main( )
{
  int  a = -1;
  short b = a;
  unsigned u = 32767;
  unsigned long L = -32768;
	
  printf ("a=%d, a=%u---(a=%%d, a=%%u)\n", a, a);
  printf ("a=%hx, a=%X---(a=%%hx, a=%%X)\n", a, a);
  printf("b=%hd, b=%hu--------(b=%%hd, b=%%hu)\n", b, b);
  printf("b=%hx, b=%X---(b=%%hx, b=%%X)\n", b, b);
  printf ("u=%o, u=%X------(u=%%o, u=%%X)\n", u, u);
  printf ("u=%#010X---------(u=%%#010X)\n", u);
  printf ("u=%#10.10X-------(u=%%#10.10X)\n", u);
  printf ("L=%lX-----------(L=%%lX)\n",L);
  printf ("L=%-#14.10X-----(L=%%-#14.10X)\n", L);
  return 0;
}   
