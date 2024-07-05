#include <stdio.h>
#include <conio.h>
	
int main()
{
  char ch, ch1, ch2;

  ch = getche();   //读取一字符  
  putchar('\n');   //换行
  ch1 = ch == 'a' ? 'z' : ch - 1;         //求前驱字符
  ch2 = ch == 'z' ? 'a' : ch + 1;         //求后继字符
  printf("ch1 = %c, ch2 = %c\n",ch1,ch2);  //显示结果
  return 0;
}
