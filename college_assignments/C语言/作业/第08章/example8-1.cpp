#include <stdio.h>
#include <math.h>

void showerror();  //����showerror������ԭ��

int main()
{
  int a;

  scanf("%d",&a);
  while (a < 0)
  {
	showerror();  //����showerror������ʾ�����
    scanf("%d",&a);
  }
  printf("sqrt(a) = %.2f\n",sqrt(a));
  return 0;
}

void showerror()   //�����Ķ���
{
  printf("input error!\n");
}
