/* This is the third C program */
#include  <stdio.h>   //预处理命令

int max(int a, int b);  //自定义函数声明

int main( )  //无参数、无返回值的主函数
{
  int x, y, z;  //定义三个整型变量x,y,z
	
  scanf("%d%d", &x, &y);  //通过键盘对变量x,y赋值
  z = max(x, y);          //调用自定义函数max求x,y的最大值，将结果赋给z
  printf("max = %d\n", z);  //库函数调用
  return 0;
}

//用户自定义函数,求两个数中的最大值
int max(int a, int b)  //带有两个形参，有返回值
{
  int c;    //定义一个整型变量

  if (a > b)  //如果a大于b
c = a;   //将a的值赋给c
  else        //否则(a小于或等于b)
     c = b;   //将b的值赋给c
  return(c);  //将c的值返回
}
