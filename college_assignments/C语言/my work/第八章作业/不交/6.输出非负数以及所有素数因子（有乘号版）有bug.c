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
	int i, cnt, sum, k,n[100];
	sum = a;
	for(i = 2, cnt = 0; a >= 2; i++, cnt++)
	{
		if(a % i == 0)
		{
			a = a / i;
			n[cnt] = i;
			printf("%d", i);
			k = k * n[cnt];
			if(k != sum)
			printf(" * ");
			i = i - 1;
		}
	}
	return;
}

void IsPrime(int a)
{
	int i, flag = 0;//flag == 0������ 
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
