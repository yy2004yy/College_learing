#include <stdio.h>
int main()
{
	int i, j, cnt, m;
	i = 1, j = 1, cnt = 0;

	while(i <= 9)
	{
		for(m =1; m < i;m++)
		printf("       ");//�����������ǵ������������ �� 
		
		while(j <= 9)
		{
			if(i <= j)
			printf("%d*%d=%-2d ", i, j, i*j);//�����������С�ڻ�����������Ĺ�ʽ �� 
			cnt++;j++;
			
			if(cnt % 9 == 0)//ÿ����Ÿ���ʽ��һ�� �� 
			printf("\n");
		
		}
		i++;
		j = 1;//��j���¸�ֵ �� 
	}
 }
