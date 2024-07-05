#include <stdio.h>
int main ()
{
	int a[10], i, sum, max, min, ma, mi, t; 
	double average;
	
	printf("请输入十个整数：\n");
	for(i = 0; i <= 9; i++)
	scanf("%d", &a[i]);
	
	for(i = 0, sum = 0; i <= 9; i++)
	{
		sum = sum + a[i];
	}
	average = sum / 10.0; 
	printf("这十个数的平均数等于：%lf;\n\n", average);
	
	max = a[0];
	for(i = 1; i <= 9; i++)
	{
		if(max < a[i])
		{
		max = a[i];
		ma = i + 1;
		}
	 } 
	printf("这十个数中的最大值等于：%d\n", max);
	printf("%d在此数组的位置是第%d个;\n\n", max, ma);
	
	min = a[0];
	for(i = 1; i <= 9; i++)
	{
		if(min > a[i])
		{
		min = a[i];	
		mi = i + 1; 	
		}
	 } 
	printf("这十个数中的最小值等于：%d\n", min);
	printf("%d在此数组的位置是第%d个;\n\n", min, mi);
	
	//t = ma; 
	//ma = mi;
	//mi = t;
	
	t = a[ma-1];
	a[ma-1] = a[mi-1];
	a[mi-1] = t;
	
	printf("最大值与最小值调换之后的数组：\n");
	for(i = 0; i <= 9; i++)
	printf("%d ", a[i]);
	
	return 0;
 } 
