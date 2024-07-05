#include <stdio.h>

int main( )
{
  unsigned int a = 6;
  int b = -20;

  printf(" a + b = %d\n", a + b);
  printf("(a + b) > 6?  %s\n", (a + b) > 6 ? "Yes" : "No");
  printf("(6 + b) > 6?  %s\n", (6 + b) > 6 ? "Yes" : "No");
  return 0;
}
