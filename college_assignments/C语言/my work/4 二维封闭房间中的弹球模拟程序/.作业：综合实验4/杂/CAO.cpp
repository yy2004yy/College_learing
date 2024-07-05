//此间彼方流浪,分不清决绝和迷惘
//2020.6.19
//曹弈轩 2019282129

#include<stdio.h>
#include<math.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

//界面的长和宽
#define HIGN 24
#define WIDTH 80

//暂定球与球之间的距离≤1时视为碰撞
#define REACH 1   

#define PI 3.14159//圆周率
#define NUM 50	//球的最大数量
int COUNT = 0;

struct BALL {
	char body;//单个字符，表示球在dos控制台应有的形态
	int sel; //当前球的颜色。0表示第一种颜色，1表示第二种颜色
	int wX; //在二维数组中，球在x方向的实际显示位置（整数）
	int wY; //在二维数组中，球在y方向的实际显示位置（整数）
	double X; //球在x方向的精确位置（实数）
	double Y; //球在y方向的精确位置（实数）
	double dX; //球在x方向的速度（实数）
	double dY; //球在y方向的速度（实数）
};

void Manage(struct BALL*, int);//每一个周期进行的一次处理
void print_pos(struct BALL*, int);//一组球的输出函数
void swap(double*, double*);//double类型的交换函数
void color(const unsigned short);//设定颜色的函数

int main() {
	srand(time(NULL));

	printf("请输入球的个数：");
	int num;//球的个数
	scanf("%d", &num);
	if (num > NUM)num = NUM;
	struct BALL *ball = (struct BALL*)malloc(sizeof(struct BALL) * num);
	if(ball == NULL)
	{
		printf("Insufficient memory available.");
		exit(-1);
	}

	for (int i = 0; i < num; i++) {
		(ball + i)->sel = rand() % 15 + 1;	//颜色
		(ball + i)->X = rand() % WIDTH + 1;	//x精确坐标
		(ball + i)->Y = rand() % HIGN + 1;	//y精确坐标

		//此判断看似多余，其实是为了防止有些时候，球被“撞”出边界，
		//以至于常年平行于边界低速运动，按正常的四舍五入无法显示出来
		if ((ball + i)->X < 1)							//边界情况
			(ball + i)->wX = 1;
		else if ((ball + i)->X >WIDTH)					//边界情况
			(ball + i)->wX = WIDTH;
		else 
			(ball + i)->wX = (int)((ball + i)->X+0.5);	//四舍五入

		if ((ball + i)->Y < 1)							//边界情况
			(ball + i)->wY = 1;							
		else if ((ball + i)->Y > HIGN)					//边界情况
			(ball + i)->wY = HIGN;
		else
			(ball + i)->wY = (int)((ball + i)->Y+0.5);	//四舍五入

		(ball + i)->body = 'o';//球是圆的，所以直接全部设为小写字母o

		//速度的初始化，大小为一个单位，方向随机生成
		double xita = rand() % 360;
		(ball + i)->dX = cos(PI * xita / 180);
		(ball + i)->dY = sin(PI * xita / 180);

	}

	
	while (TRUE)
	{
	//	system("CLS");
	//清屏，但我不用此法。下为更优方法，来自周宇航大佬。

	/**************************************************************/
	HANDLE hOut;
    COORD pos={0,0};
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut,pos);//重设打印起点

    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut, &cci);
    cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cci);//隐藏光标

	/**************************************************************/

		print_pos(ball, num);

		Manage(ball, num);

		printf("落地次数：%d", COUNT);
		Sleep(25);//休眠25毫秒


	}

	
	free(ball);			//其实这条是多余的
	return 1;			//这个程序不可能会有正常的返回值0，所以如果返回，则一定是非0的
}

//显示操作台和某球的实际位置
void print_pos(struct BALL* p, int num) {
	//上边界
	for (int i = 0; i < WIDTH + 2; i++)
		putchar('*');
	putchar('\n');

	//中间部分
	for (int i = 1; i <= HIGN; i++) {
		putchar('|');
		
		for (int j = 1; j <= WIDTH; j++) {
			short flag = 1;
			for (int k = 0; k < num; k++) {
			//这个循环的目的是，看一看是否在该位置已有一个（或多个）球
			//如果有一个球，马上break；
			//如果多个球，在第一个球就已经break，了。这一瞬间两球重影（肉眼无法察觉。）
			//这样做看似不美观不简洁，但是不这样做，可能导致右边界被“撞出”。
				if ((p + k)->wX == j && (p + k)->wY == i) {
					color((p + k)->sel);
					putchar((p + k)->body);
					color(7);
					flag = 0;
					break;
				}

			}
			if (flag)
				putchar(' ');
		}

		putchar('|');
		putchar('\n');
	}
	//下边界
	for (int i = 0; i < WIDTH + 2; i++)
		putchar('*');
	putchar('\n');

}

void Manage(struct BALL* p, int num) {

	//这里简便起见，直接将球设为质点，采用对心碰撞。
	//考虑球与球之间的相撞。不妨假设球的质量是一样的，无能量损失，动量守恒，即速度交换。
	for (int i = 1; i < num; i++) 
		for(int j=0;j<num-i;j++)
			if (pow((p + i)->X - (p + j)->X, 2) + pow((p + i)->Y - (p + j)->Y, 2) <= pow(REACH,2))
			{
				swap(&(p + i)->dX, &(p + j)->dX);
				swap(&(p + i)->dY, &(p + j)->dY);
			}

	//以下采用指针的方式，以便处理多个球
	for (int i = 0; i < num; i++){

		//考虑左右碰壁的情况
		if ((p + i)->X <= 1 || (p + i)->X >= WIDTH) {
			(p + i)->dX = -(p + i)->dX;
		}

		//考虑上方碰壁的情况
		if ((p + i)->Y <= 1) {
			(p + i)->dY = -(p + i)->dY;
			
		}

		//考虑下方碰壁的情况
		if ((p + i)->Y >= HIGN) {
			(p + i)->dY = -(p + i)->dY;
			putchar('\7');//发出声音
			COUNT++;//记录落地次数
		}

		//球的位置在此发生改变了,改变量为速度乘以一个时间单位 
		(p + i)->X += (p + i)->dX;
		(p + i)->Y += (p + i)->dY;
	
		
		//球的显示位置随实际位置相应改变
		if ((p + i)->X < 1)
			(p + i)->wX = 1;
		else if ((p + i)->X > WIDTH)
			(p + i)->wX = WIDTH;
		else
			(p + i)->wX = (int)((p + i)->X + 0.5);

		if ((p + i)->Y < 1)
			(p + i)->wY = 1;
		else if ((p + i)->Y > HIGN)
			(p + i)->wY = HIGN;
		else
			(p + i)->wY = (int)((p + i)->Y + 0.5);
	}
}


void swap(double* x, double* y) {
	double temp = *x;
	*x = *y;
	*y = temp;
}



void color(const unsigned short color1)
{       
	/*仅限改变0-15的颜色;如果在0-15，那么实现对应的颜色。因为如果超过15，则默认白色。*/
	if (color1 >= 0 && color1 <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	/*如果不在0-15的范围颜色，那么改为默认的颜色白色；*/
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		/*颜色对应值：
			0=黑色			      8=灰色　　
			1=蓝色			      9=淡蓝色                　　
			2=绿色			      10=淡绿色			0xa        　　
		　　	3=湖蓝色			      11=淡浅绿色		0xb　
		　　	4=红色			      12=淡红色			0xc　　
		　　	5=紫色			      13=淡紫色			0xd        　　
		　　	6=黄色			      14=淡黄色			0xe        　　
		　　	7=白色			      15=亮白色			0xf
		　　也可以把这些值设置成常量。
		*/
}

