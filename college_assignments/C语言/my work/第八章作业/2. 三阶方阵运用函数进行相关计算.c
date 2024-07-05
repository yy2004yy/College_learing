#include <stdio.h>
int main()
{
	int arrSum(int a[3][3]);
	int evaluate(int a[3][3], int sum);
	int i, j, sum;
	int array[3][3];
	
	printf("The original array:\n");
	for(i = 0; i <= 2; i++)
		for(j = 0; j <= 2; j++)
		scanf("%d", &array[i][j]);
		
	sum = arrSum(array);
	printf("The sum of the elements of the main diagonal is %d\n", sum);
	evaluate(array,sum);
	printf("The new array: \n");
	for(i = 0; i <= 2; i++)
	{
		for(j = 0; j <= 2; j++)
		printf("%d ", array[i][j]);
	printf("\n");
	}
}

int arrSum(int a[3][3])
{
	int i, j, sum;
	sum = 0;
	for(i = 0; i <= 2; i++)
	sum = sum + a[i][i];
	return (sum);
}

int evaluate(int a[3][3],int sum)
{
	int i, j;
	for(i = 0; i <= 2; i++)
		for(j = 0; j <= 2; j++)
		a[i][j] = sum;
	
		return 0;
}
