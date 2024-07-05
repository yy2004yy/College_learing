#include <stdio.h>
#include <math.h>
int main ()
{
	double a, b, c, x, k, i;
	
	printf("Input the three edge length:");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	if (fabs(a - b) == c && fabs(a - c) == b && fabs(b - c) == a && a + b > c && a + c > b && b + c > a)
	k = 1;//k = 1表示三角形成立 
	else
	k = 0;//k = 0表示不构成三角形 
	
	if (a == b || b == c || a == c)
	i = 1;//i = 1 表示三角形等腰 
	else 
	i = 0;//i = 0 表示三角形不等腰 
	
	if ( (fabs((a*a + b*b ) - c*c) < 1e-3)|| (fabs((a*a + c*c ) - b*b) < 1e-3 )|| (fabs((c*c + b*b ) - a*a) < 1e-3))
	x = 1;//x = 1 表示直角三角形 
	else 
	x = 0;//x = 0 表示非直角三角形 
	
	if (k == 1);
	else if(i == 1 && x == 1 ) printf("等腰直角三角形."); 
	else if(i == 1 && x == 0 ) printf("等腰三角形."); 
	else if(i == 0 && x == 1 ) printf("直角三角形.");
	else if(i == 0 && x == 0 ) printf("一般三角形.");
	else printf("不构成三角形.\n"); 
	
	return 0; 
}
