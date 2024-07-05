#include <stdio.h>
int main ()
{
	int n, c, x, k, num, reserve, sum;
	
	printf("请输入一个整数n:");
	scanf("%d", &n);
	
	c = n; x = n; k = n;
	num = 1; reserve = 0; sum = 0;
	
	while(c != 0)
	{
		c = c/10;
		num++;
	}
	
	while(x != 0)
	{
		reserve = reserve*10 + x%10;
		x = x/10;
	}	
	
	while(k != 0)
	{
		sum = sum + k%10;
		k = k/10;
	}
	
	printf("整数n是一个%d位数\n", num);
	printf("整数的逆序输出是%d\n", reserve);
	printf("整数n的各位数之和是%d\n", sum);
	
	return 0;
 } 
