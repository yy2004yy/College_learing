#include <stdio.h>
int main ()
{
	int n, c, x, k, num, reserve, sum;
	
	printf("������һ������n:");
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
	
	printf("����n��һ��%dλ��\n", num);
	printf("���������������%d\n", reserve);
	printf("����n�ĸ�λ��֮����%d\n", sum);
	
	return 0;
 } 
