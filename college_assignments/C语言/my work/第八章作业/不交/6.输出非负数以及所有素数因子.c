#include <stdio.h>
#include <math.h>
void prime_fact(int);
void IsPrime(int);
int main()
{
	int n;
	printf("Please enter a postive integer: n = ");
	scanf("%d", &n);
	IsPrime(n);
}
void prime_fact(int a)
{
	int i;
	for(i = 2; a >= 2; i++)
	{
		if(a % i == 0)
		{
			a = a / i;
			printf("%d", i);
			if(a != 1)
			printf(" * "); 
			
			
			i = i - 1;
		}
	}
	return;
}

void IsPrime(int a)
{
	int i, flag = 0;//flag == 0ÊÇËØÊý 
	for(i = 2; i < sqrt(a); i++)
	{
		if(a % i == 0)
		{
		printf("%d is not a prime number, its factorization is:\n%d = ", a, a);
		flag = 1;
		break;
		}
	}		
	
	
	if(flag == 1)
	prime_fact(a);
	else
	printf("No factor, it is a prime.\n");
}
