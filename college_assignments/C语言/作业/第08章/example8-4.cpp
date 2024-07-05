#include <stdio.h>

int max(int a,int b);  //函数的原型声明

int main()
{
  int a,b,c;

  scanf("%d%d",&a,&b);
  c = max(a,b);  //函数调用
  printf("the biggest number is : %d\n",c);
  return 0;
}


int max(int a, int b)   //函数定义，带参数有返回值
{
  return(a > b ? a : b);
}
