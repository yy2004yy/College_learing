#include <stdio.h>
int main()
{
	int x;
	printf("请输入一个四位数："); 
	scanf("%4d", &x); 
	
	int a1, a2, a3, a4;
	a1 = x / 1000 ;
	a2 = (x - a1*1000) / 100 ;
	a3 = (x - a1*1000 - a2*100)/10 ;
	a4 = x - a1*1000 - a2*100 - a3*10;
	
	printf("%d%d%d%d", a4, a3, a2, a1);
	return 0;
 } 
