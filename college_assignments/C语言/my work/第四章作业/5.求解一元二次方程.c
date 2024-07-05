#include <stdio.h>
#include <math.h>
int main()
{
	double  a, b, c, disc, x1, x2, p, q;
	printf("ax*x + b*x + c = 0\n");//解一元二次方程
	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);

	disc = b*b - 4*a*c;
	 
	if(disc < 0)
	printf("has not real roots\n");
	
	else
	{
		p = -b/(2.0*a);
		q = sqrt(disc)/(2.0*a);
		x1 = p + q;
		x2 = p - q;
		printf("real roots:\nx1 =%6.2f\nx2 =%6.2f\n", x1, x2);
			}
			
	return 0;
 } 
