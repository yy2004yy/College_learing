#include <stdio.h>
#include <math.h>
int main ()
{
	double a1, q, a, S10;
	
	a1 = 3.14;
	q = 2;
	a = pow(2 , 10);
	S10 = ((a1*(1 - a))/(1 - q));
	
	printf("S10 = %lf", S10);
	
	return 0;
	
}
