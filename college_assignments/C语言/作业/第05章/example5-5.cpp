#include <stdio.h>

int main()
{
  float a, b;    //存放两个数的变量
  int tag = 0;   //运算合法的标志，0--合法，1--非法
  char ch;       //运算符变量
  float result;  //运算结果变量
  
  printf("input two number: ");  //提示输入两个数
  scanf("%f%f", &a, &b);         //输入两个数
  fflush(stdin);                 //清键盘缓冲区
  printf("input arithmetic lable(+ - * /): ");   //提示输入运算符
  scanf("%c", &ch);              //输入运算符
   
  switch(ch)  //根据运算符来进行相关的运算
  {
    case '+':  result = a + b;   break;   //加法运算
    case '-':  result = a - b;   break;   //减法运算
    case '*':  result = a * b;   break;   //乘法运算
    case '/':  if (!b)  //除法运算，判除数是否为0 
			   {
				 printf("divisor is zero!\n");  //显示除数为0 
				 tag = 1;  //置运算非法标志
			   }
		       else  //除数非0
				 result = a / b;  //计算商
			   break;
    default:   printf("illegal arithmetic lable\n");  //非法的运算符
		       tag = 1;   //置运算非法标志
  }
  
  if (!tag)  //运算合法，显示运算结果
	 printf("%.2f %c %.2f = %.2f\n", a, ch, b, result);
  return 0;
}	
