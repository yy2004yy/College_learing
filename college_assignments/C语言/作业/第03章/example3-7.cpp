#include  <stdio.h>
	
int main()
{
  int a = 2, b = 4;
  int c,d;

  c = a++;   //�ȼ���c = a; �� a = a + 1; �������
  d = --b;   //�ȼ��� b = b - 1; �� d = b; �������
  printf("a = %d, b = %d\n",a,b);
  printf("c = %d, d = %d\n",c,d);
  return 0;
}
