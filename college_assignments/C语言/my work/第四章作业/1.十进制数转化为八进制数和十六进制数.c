#include <stdio.h>
int main ()
{
	int x ;
	
	printf("输入一个十进制正整数 x = "); 
	scanf("%d", &x);
	printf("八进制数：%o\n十六进制数：%x", x, x);
	
	return 0;
	
 } 
