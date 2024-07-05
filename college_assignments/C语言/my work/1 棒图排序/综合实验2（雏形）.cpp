/**
 * @author: 2022280380 Ye Yang
 * @description: bubble & selection sort algorithms of random number, and bar charts
 * @version: v0.01
 * @date: 2022-11-25 15:30:00 
 **/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int rArray[20], cArray[51], cnt, i, j ,flag, t, k;
	
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
		while(cnt <= rArray[i])
		{
			printf("*");
			cnt++;
			if(cnt > rArray[i])
			printf("\n"); 
		}//利用循环来 实现每一个数的输出 
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
		while(cnt <= rArray[i])
		{
			printf("*");
			cnt++;
			if(cnt > rArray[i])
			printf("\n");
		}
	}
	
	
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
		while(cnt <= rArray[i])
		{
			printf("*");
			cnt++;
			if(cnt > rArray[i])
			printf("\n");
		}
	}
		
		
		
		
		
	 } 
	
	
	
	

