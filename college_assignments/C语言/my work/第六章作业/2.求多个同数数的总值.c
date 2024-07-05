#include <stdio.h>
#include <math.h>
int main ()
{
	int n, a, i, W, S;//a是一个属于0~9之间的整数
	printf("编程计算 a + aa + aaa + ... + aa...a(n 个 a)的值，请输入n和a的值：\n");
	
	printf("n = ");
	scanf("%d", &n);
	printf("a = ");
	scanf("%d", &a);
	
	i = 1;
	S = 0;
	W = 0;
	
	while(i <= n) 
	{
		W = a + W *10;
		S = S + W;
		i++;
	}

	printf("所求总值：%d", S);
	printf("%d+%d%d+%d%d%d+...+%d%d...%d(%d个%d)的值为%d", a, a, a, a, a, a, a, a, a, n, a, S);
	return 0;
	
 } 
