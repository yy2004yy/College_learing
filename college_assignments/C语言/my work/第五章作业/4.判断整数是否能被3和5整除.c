#include <stdio.h>
int main ()
{
	int x ;
	
	printf("����һ������x��"); 
	scanf("%d", &x);
	
	if(x % 3 == 0)
	printf("�������ܱ�3����;\n");
	else 
	printf("���������ܱ�3����;\n");
	
	if(x % 5 == 0)
	printf("�������ܱ�5����;\n");
	else 
	printf("���������ܱ�5����;\n");
	
	if(x % 3 == 0 && x % 5 == 0)
	printf("��������ͬʱ��3��5����;\n");
	else 
	printf("����������ͬʱ��3��5����;\n");
	
	return 0;	
	
 } 
