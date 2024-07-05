#include <stdio.h>
#include <stdlib.h>
#include <time.h>//使用当前时钟作为种子
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
	
	flag = 0;//初始化旗帜的参数
	if(( x>0 && x<779 )&&( y>481 && y<562 ))
	{
	flag = 'A';//对旗帜参数进行更改
	printf("“你现在在A区，小心地雷！”\n");
	}
	else if(( x>0 && x<155 )&&( y>160 && y<481 ))
	{
	flag = 'B';//对旗帜参数进行更改
	printf("“你现在在B区，小心有陷阱！”\n");
	}
	else if(( x>0 && x<779 )&&( y>0 && y<160 ))
	{
	flag = 'C';//对旗帜参数进行更改
	printf("“你现在在C区，小心敌人埋伏！”\n");
	}
	else if(( x>457 && x<779 )&&( y>160 && y<481 ))
	{
	flag = 'D';//对旗帜参数进行更改
	printf("“你现在在D区，可以补充武器！”\n");
	}
	else if(( x>155 && x<457 )&&( y>160 && y<481 ))
	{
	flag = 0;//对旗帜参数进行更改
	printf("“你现在在O区，快去解救人质！”\n");
	}
	else if( x<0 || x>799 || y>562 || y<0 )
	{
	flag = 'N';//对旗帜参数进行更改
	printf("“你落在了任务区外！”\n");
	}
	else
	{
	flag = 'N';//对旗帜参数进行更改
	printf("“你落在了区域边界电网上！”\n");
	}
	
	srand((unsigned)time(NULL));//初始化随机数
	
	switch(flag)
	{
	case 'A':
	{
		printf("\n开始人质解救任务\n你正在A区，遇到A区守卫; 转动转盘进入O区开始解救人质；\n规则：如果你的数字大于或等于门卫的数字的大小，则进入O区，反之，遇到危险；\n\n"); 
		while(1)
		{
			printf("请按W键产生你的赌盘数字；\n");
			fflush(stdin);
			scanf("%c", &w);//清除之前缓冲区存留下来的回车换行符
			
			if( w == 'W' ) //如果输入的字符不符合则无限重复提醒
			{
			W = rand() % 100;
			printf("你的赌盘W的数字是：%d\n\n", W);
			break;//如果输入的字符符合则跳出循环 
			}
			else 
			{
			printf("error; 请按W键; \n\n");
			continue;//输入字符不符合则提醒之后继续循环 
			}
		}
	
		while(1)
		{
			printf("请按G键产生门卫的赌盘数字；\n");//如果输入的字符不符合则无限重复提醒
			fflush(stdin);//清除之前缓冲区存留下来的回车换行符
			scanf("%c", &g);
			
			if( g == 'G' )
			{
			Wa = rand() % 10 + 80;//使门卫的数字在80至90之间出现
			printf("门卫的赌盘Wa的数字是：%d\n\n", Wa); 
			break;
			}
			else 
			printf("error; 请按G键; \n\n");
			continue;
		}
		
			fflush(stdin);//清除之前缓冲区存留下来的回车换行符
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
			fflush(stdin);//清除之前缓冲区存留下来的回车换行符
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
			fflush(stdin);//清除之前缓冲区存留下来的回车换行符
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
		
			fflush(stdin);//清除之前缓冲区存留下来的回车换行符
			if( W < Wb )//比较赌盘上面数字的大小给出结果
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
			fflush(stdin);//清除之前缓冲区存留下来的回车换行符
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
			fflush(stdin);//清除之前缓冲区存留下来的回车换行符
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
		
			fflush(stdin);//清除之前缓冲区存留下来的回车换行符
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
			fflush(stdin);//清除之前缓冲区存留下来的回车换行符
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
			fflush(stdin);//清除之前缓冲区存留下来的回车换行符
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
		
			fflush(stdin);//清除之前缓冲区存留下来的回车换行符
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
