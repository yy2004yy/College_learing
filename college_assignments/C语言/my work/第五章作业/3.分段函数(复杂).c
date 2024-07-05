#include <stdio.h>
int main()
{
	float x ,y;
	
	printf("x = ");
	scanf("%f", &x);
	
	if(x < 1)
	{
		y = x;
		printf("y = %.2f", y);
	}

	else if(x < 10)
	{
		y = 2*x - 1;
		printf("y = %.2f", y);
	}
	
	else
	{
		y = 3*x - 11;
		printf("y = %.2f", y);
	}
	
	return 0;
	
 } 
