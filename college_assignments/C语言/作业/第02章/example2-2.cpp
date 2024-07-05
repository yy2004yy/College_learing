/* This is the second C program */
#include <stdio.h>  //预处理命令
	
int main( )  //无参数、无返回值的函数
{
  int x, y, z;  //定义三个整型变量x,y,z

  scanf("%d%d", &x, &y);  //从键盘上输入两个整型数，分别赋给变量x和y
  z = x + y;              //将x和y的值相加赋给z
  printf("the sum of two integer is %d\n", z);  //库函数调用
  return 0;	
}
