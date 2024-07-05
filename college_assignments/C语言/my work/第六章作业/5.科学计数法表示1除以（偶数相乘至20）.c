#include <stdio.h>
#include <math.h>
int main() 
{
	double sum;
	int n;

	for(n = 0, sum = 1;n <= 20;n = n + 2)
	{
		sum = sum* (1.0/(n+2)); 
	}
	
	printf("sum = %g", sum);
	
	return 0; 
}
