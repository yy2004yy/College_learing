#include <stdio.h>
int main()
{
	int str[100], i, sum;
	
	printf("Please enter a set of integers:\n");
	for(i = 0; str[i] != '\n'; i++)
		scanf("%d", &str[i]);
	int j, cnt, t, flag, n;
	int str1[100];
	for(cnt = 1; (2*cnt) < n; cnt++ )
	{
		flag = 0;
		for(j = 0; j <= n - cnt; j = j + 2)
		{
			if(str1[j] < str1[j + 2])
			{
				t = str1[j];
				str1[j] = str1[j + 2];
				str1[j] = t;
				flag = 1;
			 } 
			if(flag == 1) break;
		}
	}
	return 0;
}
