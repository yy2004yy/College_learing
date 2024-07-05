#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
int judge = 0;
int main()
{
	int randLmt();//产生0~99的随机整数 
	char randOperator();//随机产生加减乘除的一个运算符 
	int addLmt100(int num1, int num2, int *jp); //加法 
	int subLmt100(int num1, int num2); //减法 
	int mulLmt100(int num1, int num2); //乘法 
	int divLmt100(int num1, int num2); //除法 
	
	int probNum[4] = {0, 0, 0, 0}, ansNum[4] = {0, 0, 0, 0};
	int sFlag = 1; 
	int num1, num2, oper, g, prob, ans;
	srand((unsigned)time(NULL));

	do
	{
		oper = randOperator();
		num1 = randLmt();
		num2 = randLmt(); 

		if(oper == '+')
			{
			addLmt100(num1, num2, &judge);		
			probNum[0]++;		
			if(*(&judge) == 1)
			ansNum[0]++;
			}
		else if(oper == '-')
			{
			subLmt100(num1, num2);
			probNum[1]++;
			if(subLmt100(num1, num2) == 1)
			ansNum[1]++;
			}
		else if(oper == '*')
			{
			mulLmt100(num1, num2);		
			probNum[2]++;
			if(mulLmt100(num1, num2) == 1)
			ansNum[2]++;
			}
		else
		    {
			divLmt100(num1, num2);		
			probNum[3]++;
			if(divLmt100(num1, num2) == 1)
			ansNum[3]++;
			}
	    
	    judge = 0;
		printf("想要继续答题吗？\n想继续请直接按回车，不想继续请按任意键后按回车\n");
		fflush(stdin);
		g = getchar(); 
		if(g == '\n')
		sFlag = 0;
		else if(g == 'n' || g == 'N')
		sFlag = 1;
		else
		sFlag = 1;
	}while(sFlag == 0);
	
	prob = probNum[0] + probNum[1] + probNum[2] + probNum[3];
	ans = ansNum[0] + ansNum[1] + ansNum[2] + ansNum[3];	
	printf("四种类型题目共练习%d道，共答对%d道；\n", prob, ans); 
	printf("加法共%d道，答对%d道\n", probNum[0], ansNum[0]);
	printf("减法共%d道，答对%d道\n", probNum[1], ansNum[1]);
	printf("乘法共%d道，答对%d道\n", probNum[2], ansNum[2]);
	printf("除法共%d道，答对%d道\n", probNum[3], ansNum[3]);
	return 0;
 } 

int randN1N2(int N1, int N2)//产生N1~N2的随机整数
{
	int a;
	a = rand()%(N2-N1+1) + N1;
	return(a);
 } 
 
char randOperator()//随机产生加减乘除的一个运算符 
{
	int randN1N2(int N1, int N2);//产生N1~N2的随机整数
	char c;
	c = randN1N2(42, 47);
	while(1)
	{
		if(c != 44 && c != 46)
		{
		return(c);
		break;
		}
		else
		continue;
	}
}

int randLmt()//产生0~99的随机整数 
{
	int b;
	b = rand()%100 + 0;
	return(b);
}

int addLmt100(int num1, int num2, int *jp)//加法  //jp = &judge;
{
	int ans;
	jp = &judge;
	printf("%d + %d = ", num1, num2);
	scanf("%d", &ans);

	if(ans == num1 + num2)
		{
		printf("恭喜\n");
		*jp = 1;
		}
	else
		{
		printf("抱歉\n");
		*jp = 0;
		}
		
	return(*jp);
}

int subLmt100(int num1, int num2)//减法 
{
	int ans, judge;
	int numMax, numMin;
	
	if(num1 > num2)
	{
		numMax = num1;
		numMin = num2;
	}
	else
	{
		numMax = num2;
		numMin = num1;
	}
	
	printf("%d - %d = ", numMax, numMin);
	scanf("%d", &ans);

	if(ans == fabs(num1 - num2))
		{
		printf("恭喜\n");
		judge = 1;
		}
	else
		{
		printf("抱歉\n");
		judge = 0;
		}
	
	return(judge);
}

int mulLmt100(int num1, int num2)//乘法 
{
	int ans, judge;

	printf("%d × %d = ", num1, num2);
	scanf("%d", &ans);

	if(ans == num1 * num2)
		{
		printf("恭喜\n");
		judge = 1;
		}
	else
		{
		printf("抱歉\n");
		judge = 0;
		}
		
	return(judge);
}

int divLmt100(int num1, int num2)//除法 
{
	int ans, judge;
	do
	{
		num1 = randLmt();
		num2 = randLmt(); 
	}while(num1 % num2 != 0);
	
	printf("%d ÷%d = ", num1,  num2);
	scanf("%d", &ans);	

	if(ans == num1 / num2)
		{
		printf("恭喜\n");
		judge = 1;
		}
	else
		{
		printf("抱歉\n");
		judge = 0;
		}
	
	return(judge);
}


















