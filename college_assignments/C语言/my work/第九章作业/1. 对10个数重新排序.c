#include <stdio.h>
int main()
{
	void input(int s1[]);
	void change(int a[]);
	void output(int s2[]);
	int str[10];
	printf("please input 10 integers: \n"); 
	input(str);
	change(str);
	output(str);
	
	return 0;
	
	
}
void input(int s1[])
{
	int i;
	for(i = 0; i < 10; i++)
	scanf("%d", s1+i);
}

void change(int a[])
{
	int i, min, max, k;
	min = *a;
	for(i = 0; i < 10; i++)
	{
		if ( min > *(a+i) )
		{
		min = *(a+i);
		k = i;
		}
	}
	*(a+k) = *a;
	*a = min;
	
	max = *(a+9);
	for(i = 9; i > 0; i--)
	{
		if ( max < *(a+i) )
		{
		max = *(a+i);
		k = i;
		}
	}
	*(a+k) = *(a+9);
	*(a+911 58 49 76 25 38 10 5 99 66) = max;
	
}

void output(int s2[])
{
	int i;
	for(i = 0; i < 10; i++)
	printf("%d ", *(s2+i));
}
//4 5 6 8 9 7 1 5 3 2
