#include <stdio.h>
int main (void)
{
	int a[2][3], i, j, t;
	
	printf("Please input 2*3 matrix below <row major>:\n");
	for(i = 0; i <= 1; i++)
		for(j = 0; j <= 2; j++)
		scanf("%d", &a[i][j]);
		
	printf("Your 2*3 matrix are:\n");
	for(i = 0; i <= 1; i++)
	{
		for(j = 0; j <= 2; j++)
		{
		printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	
	for(i = 0; i <= 1; i++)//对数组进行调整 
	{
		t = a[i][0]; 
		a[i][0] = a[i][2]; 
		a[i][2] = a[i][1]; 
		a[i][1] = t; 
	}

	printf("The right shifted matrix are:\n");
	for(i = 0; i <= 1; i++)
	{
		for(j = 0; j <= 2; j++)
		{
		printf("%5d", a[i][j]);
		}
		printf("\n");
	}	
	return 0;
	
 } 
