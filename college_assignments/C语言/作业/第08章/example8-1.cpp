#include <stdio.h>
#include <math.h>

void showerror();  //声明showerror函数的原型

int main()
{
  int a;

  scanf("%d",&a);
  while (a < 0)
  {
	showerror();  //调用showerror函数显示输入错
    scanf("%d",&a);
  }
  printf("sqrt(a) = %.2f\n",sqrt(a));
  return 0;
}

void showerror()   //函数的定义
{
  printf("input error!\n");
}
