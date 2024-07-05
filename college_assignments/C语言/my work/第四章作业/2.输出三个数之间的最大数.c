#include <stdio.h>
int main()
{
	float a, b, c, t, max;
	printf("a = ") ;
	scanf("%f", &a);
	printf("b = ");
	scanf("%f", &b);
	printf("c = ");
	scanf("%f", &c);
	
	if(a > b)
	    t = a;
	else 
	    t = b;
	    
	if(t > c)
	    max = t;
	else
	    max = c;
	    
	printf("max = %f", max);
	
	return 0;
 } 
