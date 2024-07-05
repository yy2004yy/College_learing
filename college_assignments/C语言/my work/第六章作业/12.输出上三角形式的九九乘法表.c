#include <stdio.h>
int main()
{
	int i, j, cnt, m;
	i = 1, j = 1, cnt = 0;

	while(i <= 9)
	{
		for(m =1; m < i;m++)
		printf("       ");//控制在下三角的区域不输出数字 ； 
		
		while(j <= 9)
		{
			if(i <= j)
			printf("%d*%d=%-2d ", i, j, i*j);//仅输出行序数小于或等于列序数的公式 ； 
			cnt++;j++;
			
			if(cnt % 9 == 0)//每输出九个公式换一行 ； 
			printf("\n");
		
		}
		i++;
		j = 1;//对j重新赋值 ； 
	}
 }
