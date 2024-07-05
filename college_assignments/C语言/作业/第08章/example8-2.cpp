#include <stdio.h>
#include <conio.h>
#include <ctype.h>

sum();  //声明sum函数的原型

int main()
{
  int tot;
  
  tot = sum();   //调用sum函数
  if (tot == -1)
     printf("\nnot select!\n");
  else
	 printf("\nthe result is : %d\n",tot);
  return 0;
}

 sum()   //函数的定义
{
  int i,tot = 0;
  char key;
  
  key = getche();
  if (key != '0' && key != '1')
      return(-1);

  for(i = (key == '0') ? 2 : 1; i <= 100; i += 2)
	  tot += i; 
  return(tot);
}
