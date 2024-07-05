#include <stdio.h>

int main()
{
  int year, leap = 0;	  // leap=0：预置为非闰年

  printf("Please input the year: ");  //提示输入年份
  scanf("%d", &year);     //输入年份
  
  if (year % 4 == 0)      //如果被4整除  
     if (year % 100 != 0) //如果不被100整除
		leap = 1;         //置为闰年
  if (year % 400 == 0)    //如果被400整除
   	 leap = 1;            //置为闰年
  
  //输出结果
  if (leap) //如果是闰年(leap==1)  
	 printf("%d is a leap year.\n", year);
  else   
	 printf("%d is not a leap year.\n", year);
  return 0;
}	
