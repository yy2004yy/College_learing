#include <stdio.h>
int main()
{
	int a[4][4], i, j, n, c, sum, cheif, deputy;
	cheif = 0; deputy = 0; sum = 0;
	
	for(i = 0; i <= 3; i++)
		for(j = 0; j <= 3; j++)
			scanf("%d", &a[i][j]);
			
	printf("四阶矩阵为：\n") ;
	for(i = 0; i <= 3; i++)
	{
		for(j = 0, n = 1; j <= 3; j++, n++)
		{
			printf("%5d", a[i][j]);
			if( n % 4 == 0) printf("\n"); 
		 } 	 
	}
				
	for(j = 0; j <= 3; j++)
	{
		c = j + 1;
		sum = a[0][j] + a[1][j] + a[2][j] + a[3][j];
		printf("第%d列的各元素之和等于%d\n", c, sum);
		sum = 0;
	}

	for(n = 0; n <= 3; n++)
	{
		cheif = cheif + a[n][n];
	}
	printf("主对角线各元素之和等于%d\n", cheif);
	
	for(n = 0; n <= 3; n++)
	{
		deputy = deputy + a[n][3 - n];
	}
	printf("副对角线各元素之和等于%d\n", deputy);	
	
	return 0;
}
