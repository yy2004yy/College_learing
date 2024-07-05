#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main ()
{
	printf("猜数游戏：\n游戏规则：计算机随机“想 ”一个整数，由你来猜；如果你猜的数太小则提醒Higher，如果你猜的数太大则提醒Lower；\n"); 
	
	srand((unsigned)time(NULL));
	int aim = rand() % 100+1;  //随机生成0～100
	int cnt = 0, n;
	
	printf("提示：你只有7次机会猜数字，每次猜的数字在0～100之间:>\n");
	
	while(cnt < 7)
	{
		printf("你猜的数：") ;
		scanf("%d", &n);
		
		if( n < aim )
		{printf("Higher\n"); cnt++;}
		else if( n == aim )
		{printf("You won!\n"); cnt++;break;}
		else
		{printf("Lower\n"); cnt++;}
		
	}
	
	if (cnt == 7)
	printf("You failed!");
	
	return 0;
}

