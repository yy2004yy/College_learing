//主函数
#include "head.h"
 
void main()
{
	int n,p=0;
 
 
	printf("请输入弹球的个数:");
	scanf("%d", &n);
	
	if (n < 1)
		n = 1;
	else if (n > NUM) 
		n = NUM;
	struct BALL b[NUM];
	srand(time(NULL));
	initBall(b, n);
	redrawCWin(b, n);
	while(1)
	{
		system("CLS");	
		p+=moveBall(b, n,p);
		printf ("落地次数：%d",p);
		redrawCWin(b, n);
		delay(50);
		
	}
 
}
