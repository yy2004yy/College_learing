#include <stdio.h>
int main ()
{
	int str[100], i, j, k, n, g;
	
	printf("������һ���Ѿ��ź������򣩵��������飺\n");//�� 1 2 5 6 8 9 10 12 
	
	i = 0; 
	do
	{
		scanf("%d", &str[i]);
		i++;
	} while(getchar() != '\n');//�����س���ʱ��ֹ���� 
	

	printf("������Ҫ����������������\n");
	scanf("%d", &k);
	
	j = 0;
	while(j < i)
	{
		if(k >= str[j] && k <= str[j+1]) //���� k 
		{
			for(g = i; g > j+1; g--)
			{
				str[g] = str[g-1];
			}
			str[j+1] = k;
			break;//����ɹ�����������ѭ�� 
		}		 
		j++;
	 } 
	
	printf("�������ֺ�������飺\n");
	for(j = 0; j <= i ; j++)
	printf("%d ", str[j]);
	
	return 0;
}

