#include <stdio.h>
int main ()
{
	int i, a, b, c;
	i = 1; a = 1; b = 0;
	
	printf("���1000���ڵ����������������ӣ�");//������һ����������������֮���Ƿ������������ 
	
	while (i <= 1000)
	{
		i++;//�Ա���iÿ����һ��ֵ֮��� 1  
		
		while(a < i)//һ�������������ܱ���������ҪС 
		{
			if(i % a == 0)//a��i������ 
			{
			b = b + a;
			a++; 
			}
			else
			{
			a++;
			continue;
			}
		}
		
		if( b == i ) //�ж���������������֮���Ƿ������������ 
		{
			printf("\n%d its factors are ", i);
	    	a = 1;//��a���¸�ֵ 
			while(a < i) 
			{
				if(i % a == 0)//a��i������ 
				{
				printf("%d��", a);
				a++; 
				}
				else
				{
				a++;
				continue;
				}
			}
		}
		
		b = 0; a = 1; //��a �� b�ٴ����¸�ֵ�� 
	}
	return 0;
}
