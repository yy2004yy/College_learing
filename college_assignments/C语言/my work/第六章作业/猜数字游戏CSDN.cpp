#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu();//菜单
int game();//游戏
#define _CRT_SECURE_NO_WARNINGS
 
void menu()
{
	printf("***************************\n");
	printf("********** 1.play *********\n");
	printf("********** 0.exit *********\n");
	printf("***************************\n");
}
int game()         //return 0：   游戏完成        return 1：   游戏未完成
{
	int guess = 0;
	int aim = rand() % 100+1;     //生成0～100
 	//printf("%d\n",aim);
	int cnt = 0;                 //控制选择次数
	printf("提示：你有8次机会猜数字，每次猜的数字在0～100区间:>\n");
	system("pause");
	while (1)
	{
  	printf("请猜数字：\n");
  	scanf("%d", &guess);
  	if (guess > aim)
   	printf("猜大了\n");
  	else if (guess == aim)
  	{
   printf("恭喜你，猜对了！\n");
   return 0;
  }
  else
   printf("猜小了\n");
  cnt++;
  if (cnt == 8)
  {
   printf("游戏结束，失败！:>\n");
   system("pause");
   system("cls");
   return 1;
  }
 }
}
#define _CRT_SECURE_NO_WARNINGS

//猜数字
 
int main()
{
 int input = 0;
 srand((unsigned int)time(NULL));       //生成随机数
 system("color f3");
 
 do
 {
  menu();
  printf("请选择:>\n");
  scanf("%d", &input);
  switch (input)
  {
   case 1:
   input=game();
   break;
   case 0:
   printf("游戏结束\n");
   break;
   default:
   printf("选择错误，请重新选择\n");
   break;
  }
 
 } while (input);
 
 return 0;
}
