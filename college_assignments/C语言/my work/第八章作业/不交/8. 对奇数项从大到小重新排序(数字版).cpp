#include <stdio.h>
void jsSort(char str1[100], int n);
int main()
{
	int  i = 0, sum;
	char str[100]; 
	printf("Please enter a set of integers:\n");
	do
	{
		scanf("%c", &str[i]);
		i++;
	}while(getchar() != '\n');
	
	/*for(i = 0; getchar() != '\n'; i++)
		scanf("%d", &str[i]);*/

	sum = i;
	jsSort(str, i);
	
	for(i = 0; i < sum; i++)
		printf("%c ", str[i]);
		
	return 0;
 } 
 
void jsSort(char str1[100], int n)
{
	int j, cnt, t, flag;
	for(cnt = 1; cnt < (n/2); cnt++)
	{
		flag = 0;
		for(j = 1; j <= n; j = j + 2)
		
			if(str1[j] < str1[j + 2])
			{
				t = str1[j];
				str1[j] = str1[j + 2];
				str1[j + 2] = t;
				flag = 1;
			 } 
			if(flag == 0) break;
	 	
	}
}
