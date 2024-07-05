#include  <stdio.h>
	
int main()
{
  int a = 2, b = 4;
  int c,d;

  c = a++;   //等价于c = a; 和 a = a + 1; 两条语句
  d = --b;   //等价于 b = b - 1; 和 d = b; 两条语句
  printf("a = %d, b = %d\n",a,b);
  printf("c = %d, d = %d\n",c,d);
  return 0;
}
