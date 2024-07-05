#include <stdio.h>
int main ()
{
	int i, a, b, c;
	i = 1; a = 1; b = 0;
	
	printf("输出1000以内的所有完数及其因子：");//完数：一个整数的所有因子之和是否等于整数本身 
	
	while (i <= 1000)
	{
		i++;//自变量i每检验一个值之后加 1  
		
		while(a < i)//一个整数的因子总比整数本身要小 
		{
			if(i % a == 0)//a是i的因子 
			{
			b = b + a;
			a++; 
			}
			else
			{
			a++;
			continue;
			}
		}
		
		if( b == i ) //判断整数的所有因子之和是否等于整数本身 
		{
			printf("\n%d its factors are ", i);
	    	a = 1;//对a重新赋值 
			while(a < i) 
			{
				if(i % a == 0)//a是i的因子 
				{
				printf("%d，", a);
				a++; 
				}
				else
				{
				a++;
				continue;
				}
			}
		}
		
		b = 0; a = 1; //对a ， b再次重新赋值； 
	}
	return 0;
}
