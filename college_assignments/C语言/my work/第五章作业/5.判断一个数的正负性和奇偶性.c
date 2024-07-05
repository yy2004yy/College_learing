#include <stdio.h>
int main()
{
	int x ;
	
	printf("输入一个整数x："); 
	scanf("%d", &x);
	
	if(x > 0)
		if(x % 2 == 0) printf("%d is a postive even.", x);
		else printf("%d is a postive odd.", x);
	else
		if(x == 0) printf("%d is zero.It is an even.", x);
		else if(x % 2 == 0) printf("%d is a negative even.", x);
		else printf("%d is a negative odd.", x);
		
	return 0;

 } 
