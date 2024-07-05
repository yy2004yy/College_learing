#include <stdio.h>

int main()
{
  char  c;

  while(1)
  { 
	c = getchar();              //读取一个字符
	if ( c >= 'a' && c <= 'z')  //是小写字母
	   putchar(c - 'a' + 'A');  //输出其大写字母
	else       //不是小写字母
	   break;  //循环退出
   }
  return 0;
}
