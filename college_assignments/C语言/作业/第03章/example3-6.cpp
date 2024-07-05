#include  <stdio.h>
	
int main()
{
  int a, b;
  unsigned short c;
  unsigned int u;
  long d, e;
  char ch;
  float f;

  a = 200;
  b = -1;
  c = b;
  u = b;
  d = c;
  e = u;
  ch = 'A';
  f = 32.17;
  printf("a = %d\t",a);
  printf("b = %d\t",b);
  printf("c = %d\n",c);
  printf("u = %u\t",u);
  printf("d = %ld\t",d);
  printf("e = %ld\n",e);
  printf("f = %f\n",f);
  printf("ch is %c and value is %d\n",ch,ch);
  printf("I   love C language!\rYou\n");
  return 0;
}