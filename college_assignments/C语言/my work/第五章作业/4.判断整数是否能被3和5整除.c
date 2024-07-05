#include <stdio.h>
int main ()
{
	int x ;
	
	printf("输入一个整数x："); 
	scanf("%d", &x);
	
	if(x % 3 == 0)
	printf("该整数能被3整除;\n");
	else 
	printf("该整数不能被3整除;\n");
	
	if(x % 5 == 0)
	printf("该整数能被5整除;\n");
	else 
	printf("该整数不能被5整除;\n");
	
	if(x % 3 == 0 && x % 5 == 0)
	printf("该整数能同时被3或5整除;\n");
	else 
	printf("该整数不能同时被3或5整除;\n");
	
	return 0;	
	
 } 
