#include <stdio.h>
#include <conio.h>
	
int main()
{
  char ch, ch1, ch2;

  ch = getche();   //读取一字符  
  putchar('\n');   //换行
  ch1 = 'z' - ('z' - ch + 1) % 26;         //求前驱字符
  ch2 = 'a' + (ch - 'a' + 1) % 26;         //求后继字符
  printf("ch1 = %c, ch2 = %c\n",ch1,ch2);  //显示结果
  return 0;
}
