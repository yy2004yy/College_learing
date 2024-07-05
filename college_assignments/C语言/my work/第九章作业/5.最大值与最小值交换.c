#include <stdio.h>
int main()
{
	void swap(int a[], int *n1);
	int num[100], n, i;
	printf("Please input the sum of the number:\nn = ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	scanf("%d", num+i);
	swap(num, &n);
	for(i = 0; i < n; i++)
	printf("%d ", *(num+i));
}

void swap(int a[], int *n1)
{
	int i, j, temp, max = *a, min = *a, ma, mi;
	
	for(i = 0; i < *n1; i++)
	{
		if(*(a+i)>max)
		{
		max = *(a+i);
		ma = i;
		}
	}
	
	for(j = 0; j < *n1; j++)
	{
		if(*(a+j)<min)
		{
		min = *(a+j);
		mi = j;
		}
	}
	temp = *(a + ma);
	*(a + ma) = *(a + mi);
	*(a + mi) = temp ;
}
