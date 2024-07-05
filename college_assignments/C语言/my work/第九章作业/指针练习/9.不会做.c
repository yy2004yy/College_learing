#include <stdio.h>
int main()
{
	int i, n, num[10000], cnt;
	printf("Please input a integer as the number of player: ");
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		*(num+i)=66;
	
	while(n != 1)
	{
		cnt = 0;
		for(i = 1; i <= n; i++)
		{
			if (*(num+i) != 0) *(num+i)=i;
			else 
			
			}	
			
		for(i = 1; i <= n; i++)	
		if(*(num+i) % 3 == 0)
			{
			*(num+i)=0;
			cnt++;
			}
			
		n = n - cnt;
		
		
	}
	
 } 
 

