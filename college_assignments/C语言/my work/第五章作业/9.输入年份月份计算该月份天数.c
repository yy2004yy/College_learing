#include <stdio.h>
int main()
{
	int year, month, leap;
	printf("年份："); 
	scanf("%d", &year);
	printf("月份："); 
	scanf("%d", &month);
	
	if((year % 4 == 0)&&(year % 100 != 0)||(year % 400 == 0))
	    leap = 1;//leap = 1 表示这一年为闰年 
	else 
	    leap = 0; 

	if (leap == 1)
		switch(month)
		{
			case 1: printf("该月份天数：31\n"); break;
			case 2: printf("该月份天数：29\n"); break;
			case 3: printf("该月份天数：31\n"); break;
			case 4: printf("该月份天数：30\n"); break;
			case 5: printf("该月份天数：31\n"); break;
			case 6: printf("该月份天数：30\n"); break;
			case 7: printf("该月份天数：31\n"); break;
			case 8: printf("该月份天数：31\n"); break;
			case 9: printf("该月份天数：30\n"); break;
			case 10: printf("该月份天数：31\n"); break;
			case 11: printf("该月份天数：30\n"); break;
			case 12: printf("该月份天数：31\n"); break;
			default : printf("Data error!\n");
		
			}	
	
	else
		switch(month)
		{
			case 1: printf("该月份天数：31\n"); break;
			case 2: printf("该月份天数：28\n"); break;
			case 3: printf("该月份天数：31\n"); break;
			case 4: printf("该月份天数：30\n"); break;
			case 5: printf("该月份天数：31\n"); break;
			case 6: printf("该月份天数：30\n"); break;
			case 7: printf("该月份天数：31\n"); break;
			case 8: printf("该月份天数：31\n"); break;
			case 9: printf("该月份天数：30\n"); break;
			case 10: printf("该月份天数：31\n"); break;
			case 11: printf("该月份天数：30\n"); break;
			case 12: printf("该月份天数：31\n"); break;
			default : printf("Data error!\n");
		
			}	
	
	return 0;
 } 
