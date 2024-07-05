#include <stdio.h>
int main ()
{
	int a, b;
	printf("a的初始值：");
	scanf("%d", &a );
	printf("b的初始值："); 
	scanf("%d", &b );
	
	a = a + b;
	b = a - b;
	a = a - b;
	
	printf("a的最终值：%d\nb的最终值：%d", a, b);
	return 0;
	
 } 
