#include <stdio.h>

int main()
{
  int i, j;

  for (i = 1; i <= 3; i++)
  {
	printf("i = %d: ", i);
	for (j = 1; j <= 4; j++)
	  printf("j = %-4d", j);
	printf("\n");  //¿ØÖÆ»»ÐÐ
  }
  return 0;
}