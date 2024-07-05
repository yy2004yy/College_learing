#include <stdio.h>
int main()
{
	int c;
	float f;
	printf("请输入摄氏温度：C = "); 
	scanf("%d", &c);
	f = (c + 32)*(9/5);
	printf("华氏温度：F = %.2f", f);
	return 0;

 } 
