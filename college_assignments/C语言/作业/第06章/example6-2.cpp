#include <stdio.h>
	
int main()
{
  int m, n, r;

  printf("please input two positive integer: ");
  scanf("%d%d", &m, &n);
  while (n != 0)
  {
	r = m % n;  //������
	m = n;
	n = r;
  }
  printf("Their greatest common divisor is %d\n", m);
  return 0;
}
