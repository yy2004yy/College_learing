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
	printf("��ʮ������������ͼ��\n\n");//�������ͼ�ĳ�ʼ���� 
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
		}//����ѭ���� ʵ��ÿһ��������� 
	}
	printf("\n");
	
	printf("�ȴ����̴�س�֮�����ð������......\n");	
	while(1)
	{
		if(getchar() == '\n')
		break;
	}
	printf("ð������֮��Ľ�������ͼ\n");	//ð������ 
	for(i = 1; i <= 19; i++)//ֻ��Ҫ����19��ð������ 
	{
		flag = 0;
		for(j = 0; j < 20 - i; j++)
		
			if(rArray[j] < rArray[j+1])//���Ӵ�С�� 
			{
				t = rArray[j];
				rArray[j] = rArray[j+1];
				rArray[j+1] = t;
				flag = 1;	
			}
		
		if(flag == 0) break;//�������һ�ν�����ð������֮����û�и�����������ѭ�� 
		
	}
	for(i = 0; i <= 19; i++)//���ð������֮��Ľ�������ͼ
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
	
	
	printf("\n�ȴ����̴�س�֮�����ѡ������......\n");	
	while(1)
	{
		if(getchar() == '\n')
		break;
	}
	printf("ѡ������֮��Ľ�������ͼ\n");	
	
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
		
	for(i = 0; i <= 19; i++)//���ѡ������֮��Ľ�������ͼ
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
	
	
	
	

