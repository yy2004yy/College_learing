#include <stdio.h>
int main ()
{
	int a, b;
	printf("a�ĳ�ʼֵ��");
	scanf("%d", &a );
	printf("b�ĳ�ʼֵ��"); 
	scanf("%d", &b );
	
	a = a + b;
	b = a - b;
	a = a - b;
	
	printf("a������ֵ��%d\nb������ֵ��%d", a, b);
	return 0;
	
 } 
