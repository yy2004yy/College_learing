#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main ()
{
	printf("������Ϸ��\n��Ϸ���򣺼����������� ��һ���������������£������µ���̫С������Higher�������µ���̫��������Lower��\n"); 
	
	srand((unsigned)time(NULL));
	int aim = rand() % 100+1;  //�������0��100
	int cnt = 0, n;
	
	printf("��ʾ����ֻ��7�λ�������֣�ÿ�βµ�������0��100֮��:>\n");
	
	while(cnt < 7)
	{
		printf("��µ�����") ;
		scanf("%d", &n);
		
		if( n < aim )
		{printf("Higher\n"); cnt++;}
		else if( n == aim )
		{printf("You won!\n"); cnt++;break;}
		else
		{printf("Lower\n"); cnt++;}
		
	}
	
	if (cnt == 7)
	printf("You failed!");
	
	return 0;
}

