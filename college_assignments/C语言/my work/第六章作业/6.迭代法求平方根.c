#include <stdio.h>
#include <math.h>
int main()
{
	double x, y, a, t;
	
	printf("a = ");
	scanf("%lf", &a);
	
	y = a/2;
	x = ( y + a/y )/2.0;
	
	while (fabs(x-y) > 1e-6)
	{
		t = x;
		x = ( x + a/x )/2.0;
		y = t;
	}
	
	printf("¸ùºÅx = %lf", x); 
	
	return 0;
 } 
