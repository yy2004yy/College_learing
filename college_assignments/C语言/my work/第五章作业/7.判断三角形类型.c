#include <stdio.h>
#include <math.h>
int main ()
{
	double a, b, c, x, k, i;
	
	printf("Input the three edge length:");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	if (fabs(a - b) == c && fabs(a - c) == b && fabs(b - c) == a && a + b > c && a + c > b && b + c > a)
	k = 1;//k = 1��ʾ�����γ��� 
	else
	k = 0;//k = 0��ʾ������������ 
	
	if (a == b || b == c || a == c)
	i = 1;//i = 1 ��ʾ�����ε��� 
	else 
	i = 0;//i = 0 ��ʾ�����β����� 
	
	if ( (fabs((a*a + b*b ) - c*c) < 1e-3)|| (fabs((a*a + c*c ) - b*b) < 1e-3 )|| (fabs((c*c + b*b ) - a*a) < 1e-3))
	x = 1;//x = 1 ��ʾֱ�������� 
	else 
	x = 0;//x = 0 ��ʾ��ֱ�������� 
	
	if (k == 1);
	else if(i == 1 && x == 1 ) printf("����ֱ��������."); 
	else if(i == 1 && x == 0 ) printf("����������."); 
	else if(i == 0 && x == 1 ) printf("ֱ��������.");
	else if(i == 0 && x == 0 ) printf("һ��������.");
	else printf("������������.\n"); 
	
	return 0; 
}
