#include <stdio.h>

int main()
{
  int  a = 123;
  long L = 65537;

  printf("  12345678901234567890\n");
  printf("a=%d--------(a=%%d)\n",a);
  printf("a=%6d-----(a=%%6d)\n",a);
  printf("a=%+6d-----(a=%%+6d)\n",a);
  printf("a=%-6d-----(a=%%-6d)\n",a);
  printf("a=%-06d-----(a=%%-06d)\n",a);
  printf("a=%+06d-----(a=%%+06d)\n",a);
  printf("a=%+6.6d----(a=%%+6.6d)\n",a);
  printf("a=%6.6d-----(a=%%6.6d)\n",a);
  printf("a=%-6.5d-----(a=%%-6.5d)\n",a);
  printf("a=%6.4d-----(a=%%6.4d)\n",a);
  printf("L=%ld------(L=%%ld)\n",L);
  printf("L=%hd----------(L=%%hd)\n",L);
  return 0;
}   
