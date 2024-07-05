#include <stdio.h>
int main ()
{
	int str[100], i, j, k, n, g;
	
	printf("请输入一行已经排好序（正序）的整型数组：\n");//如 1 2 5 6 8 9 10 12 
	
	i = 0; 
	do
	{
		scanf("%d", &str[i]);
		i++;
	} while(getchar() != '\n');//碰到回车键时终止输入 
	

	printf("请输入要插入此数组的整数：\n");
	scanf("%d", &k);
	
	j = 0;
	while(j < i)
	{
		if(k >= str[j] && k <= str[j+1]) //插入 k 
		{
			for(g = i; g > j+1; g--)
			{
				str[g] = str[g-1];
			}
			str[j+1] = k;
			break;//如果成功插入则跳出循环 
		}		 
		j++;
	 } 
	
	printf("插入数字后的新数组：\n");
	for(j = 0; j <= i ; j++)
	printf("%d ", str[j]);
	
	return 0;
}

