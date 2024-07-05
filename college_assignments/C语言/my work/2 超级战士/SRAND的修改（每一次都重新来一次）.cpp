#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main ()
{
	float x, y;
	int flag, i;
	char w, g;
	int W, Wa, Wb, Wc, Wd;
	
	printf("请输入你现在的位置坐标 X："); 
	scanf("%f", &x);
	printf("请输入你现在的位置坐标 Y：");
	scanf("%f", &y);
	
	flag = 0;
	if(( x>0 && x<779 )&&( y>481 && y<562 ))
	{
	flag = 'A';
	printf("“你现在在A区，小心地雷！”\n");
	}
	else if(( x>0 && x<155 )&&( y>160 && y<481 ))
	{
	flag = 'B';
	printf("“你现在在B区，小心有陷阱！”\n");
	}
	else if(( x>0 && x<779 )&&( y>0 && y<160 ))
	{
	flag = 'C';
	printf("“你现在在C区，小心敌人埋伏！”\n");
	}
	else if(( x>457 && x<779 )&&( y>160 && y<481 ))
	{
	flag = 'D';
	printf("“你现在在D区，可以补充武器！”\n");
	}
	else if(( x>155 && x<457 )&&( y>160 && y<481 ))
	{
	flag = 0;
	printf("“你现在在O区，快去解救人质！”\n");
	}
	else if( x<0 || x>799 || y>562 || y<0 )
	{
	flag = 'N';
	printf("“你落在了任务区外！”\n");
	}
	else
	{
	flag = 'N';
	printf("“你落在了区域边界电网上！”\n");
	}
	
	switch(flag)
	{
	case 'A':
	{
		printf("\n开始人质解救任务\n你正在A区，遇到A区守卫; 转动转盘进入O区开始解救人质；\n规则：如果你的数字大于或等于门卫的数字的大小，则进入O区，反之，遇到危险；\n\n"); 
		while(1)
		{
			printf("请按W键产生你的赌盘数字；\n");
			fflush(stdin);
			scanf("%c", &w);
			srand((unsigned)time(NULL));
			
			if( w == 'W' ) 
			{
			W = rand() % 100;
			printf("你的赌盘W的数字是：%d\n\n", W);
			break; 
			}
			else 
			{
			printf("error; 请按W键; \n\n");
			continue; 
			}
		}
	
		while(1)
		{
			printf("请按G键产生门卫的赌盘数字；\n");
			fflush(stdin);
			scanf("%c", &g);
			srand((unsigned)time(NULL));
			
			if( g == 'G' )
			{
			Wa = rand() % 10 + 80;
			printf("门卫的赌盘Wa的数字是：%d\n\n", Wa); 
			break;
			}
			else 
			printf("error; 请按G键; \n\n");
			continue;
		}
		
			fflush(stdin);
			if( W < Wa )
			{
			printf("“地雷爆炸，任务失败！”\n");
			}
			else 
			{
			printf("“成功进入人质 O 区，解救人质成功！”\n");	
			}
			break;
			
	}
	case 'B':
	{
		printf("\n开始人质解救任务\n你正在B区，遇到B区守卫; 转动转盘进入O区开始解救人质；\n规则：如果你的数字大于或等于门卫的数字的大小，则进入O区，反之，遇到危险；\n\n"); 
		while(1)
		{
			printf("请按W键产生你的赌盘数字；\n");
			fflush(stdin);
			scanf("%c", &w);
			
			if( w == 'W' ) 
			{
			W = rand() % 100;
			printf("你的赌盘W的数字是：%d\n\n", W);
			break; 
			}
			else 
			{
			printf("error; 请按W键; \n\n");
			continue; 
			}
		}
	
		while(1)
		{
			printf("请按G键产生门卫的赌盘数字；\n");
			fflush(stdin);
			scanf("%c", &g);
			
			if( g == 'G' )
			{
			Wb = rand() % 10 + 45;
			printf("门卫的赌盘Wb的数字是：%d\n\n", Wb); 
			break;
			}
			else 
			printf("error; 请按G键; \n\n");
			continue;
		}
		
			fflush(stdin);
			if( W < Wb )
			{
			printf("“掉入陷阱，任务失败！\n");
			}
			else 
			{
			printf("“成功进入人质 O 区，解救人质成功！”\n");	
			}
			break;
	}
	case 'C':
	{
		printf("\n开始人质解救任务\n你正在C区，遇到C区守卫;转动转盘进入O区开始解救人质；\n规则：如果你的数字大于或等于门卫的数字的大小，则进入O区，反之，遇到危险；\n\n"); 
		while(1)
		{
			printf("请按W键产生你的赌盘数字；\n");
			fflush(stdin);
			scanf("%c", &w);
			
			if( w == 'W' ) 
			{
			W = rand() % 100;
			printf("你的赌盘W的数字是：%d\n\n", W);
			break; 
			}
			else 
			{
			printf("error; 请按W键; \n\n");
			continue; 
			}
		}
	
		while(1)
		{
			printf("请按G键产生门卫的赌盘数字；\n");
			fflush(stdin);
			scanf("%c", &g);
			
			if( g == 'G' )
			{
			Wc = rand() % 10 + 60;
			printf("门卫的赌盘Wa的数字是：%d\n\n", Wc); 
			break;
			}
			else 
			printf("error; 请按G键; \n\n");
			continue;
		}
		
			fflush(stdin);
			if( W < Wc )
			{
			printf("“遭到伏击，任务失败！”\n");
			}
			else 
			{
			printf("“成功进入人质 O 区，解救人质成功！”\n");	
			}
			break;
	}
	case 'D':
	{
		printf("\n开始人质解救任务\n你正在D区，遇到D区守卫;转动转盘进入O区开始解救人质；\n规则：如果你的数字大于或等于门卫的数字的大小，则进入O区，反之，遇到危险；\n\n"); 
		while(1)
		{
			printf("请按W键产生你的赌盘数字；\n");
			fflush(stdin);
			scanf("%c", &w);
			
			if( w == 'W' ) 
			{
			W = rand() % 100;
			printf("你的赌盘W的数字是：%d\n\n", W);
			break; 
			}
			else 
			{
			printf("error; 请按W键; \n\n");
			continue; 
			}
		}
	
		while(1)
		{
			printf("请按G键产生门卫的赌盘数字；\n");
			fflush(stdin);
			scanf("%c", &g);
			
			if( g == 'G' )
			{
			Wd = rand() % 10 + 10;
			printf("门卫的赌盘Wd的数字是：%d\n\n", Wd); 
			break;
			}
			else 
			printf("error; 请按G键; \n\n");
			continue;
		}
		
			fflush(stdin);
			if( W < Wd )
			{
			printf("“武器丢失，任务失败！”\n");
			}
			else 
			{
			printf("“成功进入人质 O 区，解救人质成功！”\n");	
			}
			break;
	}
	case 'N':
	{
	printf("任务失败!\n"); break;
	}
	default: printf("任务完成，救出人质！\n");
	}
 }
