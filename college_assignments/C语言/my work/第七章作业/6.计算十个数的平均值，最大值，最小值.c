#include <stdio.h>
int main ()
{
	int a[10], i, sum, max, min, ma, mi, t; 
	double average;
	
	printf("������ʮ��������\n");
	for(i = 0; i <= 9; i++)
	scanf("%d", &a[i]);
	
	for(i = 0, sum = 0; i <= 9; i++)
	{
		sum = sum + a[i];
	}
	average = sum / 10.0; 
	printf("��ʮ������ƽ�������ڣ�%lf;\n\n", average);
	
	max = a[0];
	for(i = 1; i <= 9; i++)
	{
		if(max < a[i])
		{
		max = a[i];
		ma = i + 1;
		}
	 } 
	printf("��ʮ�����е����ֵ���ڣ�%d\n", max);
	printf("%d�ڴ������λ���ǵ�%d��;\n\n", max, ma);
	
	min = a[0];
	for(i = 1; i <= 9; i++)
	{
		if(min > a[i])
		{
		min = a[i];	
		mi = i + 1; 	
		}
	 } 
	printf("��ʮ�����е���Сֵ���ڣ�%d\n", min);
	printf("%d�ڴ������λ���ǵ�%d��;\n\n", min, mi);
	
	//t = ma; 
	//ma = mi;
	//mi = t;
	
	t = a[ma-1];
	a[ma-1] = a[mi-1];
	a[mi-1] = t;
	
	printf("���ֵ����Сֵ����֮������飺\n");
	for(i = 0; i <= 9; i++)
	printf("%d ", a[i]);
	
	return 0;
 } 
