#include  <stdio.h>         //文件包含,头文件说明
	
#define   SUM   65535       //定义符号常量SUM，值为65535
	
int main()
{
  int a, b = 20;            //定义两个整型型变量a和b，b赋初值20
  unsigned int c = 0xff;    //定义无符号整型变量c，并赋初值0xff
  short int d;              //定义有符号短整型变量d
  long e;                   //定义有符号长整型变量e
	
  a = SUM;                  //对a赋值为SUM，这时a的值是65535
  d = SUM;                  //对d赋值为SUM，这时d的值是65535
  e = 301;                  //对e赋值为301
	     
  printf("a = %d\n", a);     //以有符号十进制形式（"%d"）显示a的值
  printf("b = %d\n", b);     //以有符号十进制形式（"%d"）显示b的值
  printf("c = %d\n", c);     //以有符号十进制形式（"%d"）显示c的值
  printf("d = %d\n", d);     //以有符号十进制形式（"%d"）显示d的值
  printf("e = %d\n", e);     //以有符号十进制形式（"%d"）显示e的值
  return 0;
}

