/**
 * @author: 2022280380 Ye Yang
 * @description: bubble & selection sort algorithms of random number, and bar charts
 * @version: v0.01
 * @date: 2022-11-25 15:30:00 
 **/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printf_star(int a);
int main()
{
	
	int rArray[20], cnt, i, j ,flag, t, k;
	char cArray[51] = {'\0'};
	
	srand((unsigned)time(0));
	
	for(i = 0; i <= 19; i++)
	{
		rArray[i] = rand()% 50 + 1;
	}
	printf("二十个随机数及其棒图：\n\n");//随机数棒图的初始排序 
	for(i = 0; i <= 19; i++)
	{
		printf("[%-2d] %5d: ", i, rArray[i]);
		cnt = 1;
		printf_star(rArray[i]);
	}
	printf("\n");
	
	printf("等待键盘打回车之后进行冒泡排序......\n");	
	while(1)
	{
		if(getchar() == '\n')
		break;
	}
	printf("冒泡排序之后的结果及其棒图\n");	//冒泡排序 
	for(i = 1; i <= 19; i++)//只需要进行19次冒泡排序 
	{
		flag = 0;
		for(j = 0; j < 20 - i; j++)
		
			if(rArray[j] < rArray[j+1])//（从大到小） 
			{
				t = rArray[j];
				rArray[j] = rArray[j+1];
				rArray[j+1] = t;
				flag = 1;	
			}
		
		if(flag == 0) break;//如果有哪一次进行了冒泡排序之后发现没有更换，则跳出循环 
		
	}
	for(i = 0; i <= 19; i++)//输出冒泡排序之后的结果及其棒图
	{
		printf("[%-2d] %5d: ", i, rArray[i]);
		cnt = 1;
		printf_star(rArray[i]);
	}
	fflush(stdin);
	printf("\n等待键盘打回车之后进行选择排序......\n");	
	while(1)
	{
		if(getchar() == '\n')
		break;
	}
	printf("选择排序之后的结果及其棒图\n");	
	
	for(i = 0; i < 19; i++)
	{
		k = i;
		for(j = i+1; j < 20; j++)
		{
			if(rArray[k] > rArray[j]) k = j;
			if(k != i)
			{
				t = rArray[k];
				rArray[k] = rArray[i];
				rArray[i] = t;
			}
		}
	}
		
	for(i = 0; i <= 19; i++)//输出选择排序之后的结果及其棒图
	{
		printf("[%-2d] %5d: ", i, rArray[i]);
		cnt = 1;
		printf_star(rArray[i]);
	}
	fflush(stdin);
	 } 
	 
void printf_star(int a)//定义一个打印星星的函数 
{
	int i, star[50];
	for(i = 0; i < a; i++)
	{
	star[i] = '*';
	printf("%c", star[i]);//输出字符"*" 
	}
	star[a] = '\0';//对第a+1个数赋上终止符 
	printf("\n");//每完成对一个数的星星的打印就换行 
}
	
	
	
	

