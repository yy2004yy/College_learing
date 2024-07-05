#include <stdio.h>
#include <math.h>
#define min 100
#define max 200
int main()
{
	int prime_number(int num);
	int i, x;
	printf("输出100~200之间所有的素数：\n");
	for(i = min; i <= max; i++)
	{
		x = prime_number(i);
		if(x != 0)
		printf("%d ", i);
	}
	
	return 0;
}

int prime_number(int num)
{
	int n, k;
	k = sqrt(num);
	for(n = 2; n < num; n++)
	{
		if(num % n == 0)
		return 0;
		if(n > k)
		return 1;
	}
}

