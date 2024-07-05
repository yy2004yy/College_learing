#include "ex4pinball.h"
int times = 0; //弹球碰撞地面次数统计(全局变量)
int main()
{
	int num;//弹球的个数 num 
	//srand((unsigned)time(NULL));//初始化随机数种子
	printf("请输入球的个数（num）："); 
	scanf("%d", &num);//输入弹球的个数保存在num中，数量在1~NUM之间
	struct BALL ball[num];
	
	if (num > NUM) num = NUM;
	if (num <= 1) num = 1;
	struct BALL *b = (struct BALL*)malloc(sizeof(struct BALL) * num);
	/* 若用户输入的弹球个数小于1，则设置弹球数量为 1；若用户输入的弹球个数大于 NUM 时，则设置弹球个数为NUM；若用户输入的弹球个数在 1 到 NUM 之间，则弹球个数为用户输入的个数。 */ 
	
	if(b == NULL)
	{
		printf("Insufficient memory available.");
		exit(-1);
	}//利用动态分配内存malloc()函数给num个弹球的结构体数组分配空间
	
	//初始化num个弹球的结构体数组
	initBall(ball, num);
	
	//定义并初始化二维图像数组cWin[HEIGHT][WIDTH]
	char cWin[HEIGHT][WIDTH];
	//memset(cWin, ' ', HEIGHT*WIDTH); //二维图像数组全部初始化为空格符
	initCharPicture(cWin); //二维图像数组的边界字符初始化
	//无需任何循环直接输出该二维图像数组cWin
	
	while(1)
	{
    system("CLS"); //执行清屏命令
	initCharPicture(cWin);
    redrawCWin(ball, num);//输出小球 以及背景 
    Sleep(50);//延迟2秒 
    moveBall(ball, num);//计算小球参数的改变，计算弹球撞地次数并显示
	}
	
	//释放申请的内存空间*/
	free(b);
	fflush(stdin);
	getchar();
	
	return 0;
}
