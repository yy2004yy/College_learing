#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main ()
{
	int x, y, flag, i;
	char w, g;
	int W, Wa, Wb, Wc, Wd;
	
	printf("�����������ڵ�λ������ X��"); 
	scanf("%d", &x);
	printf("�����������ڵ�λ������ Y��");
	scanf("%d", &y);
	
	flag = 0;
	if(( x>0 && x<779 )&&( y>481 && y<562 ))
	{
	flag = 'A';
	printf("����������A����С�ĵ��ף���\n");
	}
	else if(( x>0 && x<155 )&&( y>160 && y<481 ))
	{
	flag = 'B';
	printf("����������B����С�������壡��\n");
	}
	else if(( x>0 && x<779 )&&( y>0 && y<160 ))
	{
	flag = 'C';
	printf("����������C����С�ĵ����������\n");
	}
	else if(( x>457 && x<779 )&&( y>160 && y<481 ))
	{
	flag = 'D';
	printf("����������D�������Բ�����������\n");
	}
	else if(( x>155 && x<457 )&&( y>160 && y<481 ))
	{
	flag = 0;
	printf("����������O������ȥ������ʣ���\n");
	}
	else if( x<0 || x>799 || y>562 || y<0 )
	{
	flag = 'N';
	printf("�����������������⣡��\n");
	}
	else
	{
	flag = 'N';
	printf("��������������߽�����ϣ���\n");
	}
	
	srand((unsigned)time(NULL));
	
	switch(flag)
	{
	case 'A':
	{
		printf("\n��ʼ���ʽ������\n������A��������A������; ת��ת�̽���O����ʼ������ʣ�\n�������������ִ��ڻ�������������ֵĴ�С�������O������֮������Σ�գ�\n\n"); 
		while(1)
		{
			printf("�밴W��������Ķ������֣�\n");
			fflush(stdin);
			scanf("%c", &w);
			
			if( w == 'W' ) 
			{
			W = rand() % 100;
			printf("��Ķ���W�������ǣ�%d\n\n", W);
			break; 
			}
			else 
			{
			printf("error; �밴W��; \n\n");
			continue; 
			}
		}
	
		while(1)
		{
			printf("�밴G�����������Ķ������֣�\n");
			fflush(stdin);
			scanf("%c", &g);
			
			if( g == 'G' )
			{
			Wa = rand() % 10 + 80;
			printf("�����Ķ���Wa�������ǣ�%d\n\n", Wa); 
			break;
			}
			else 
			printf("error; �밴G��; \n\n");
			continue;
		}
		
			fflush(stdin);
			if( W < Wa )
			{
			printf("�����ױ�ը������ʧ�ܣ���\n");
			}
			else 
			{
			printf("���ɹ��������� O ����������ʳɹ�����\n");	
			}
			break;
			
	}
	case 'B':
	{
		printf("\n��ʼ���ʽ������\n������B��������B������; ת��ת�̽���O����ʼ������ʣ�\n�������������ִ��ڻ�������������ֵĴ�С�������O������֮������Σ�գ�\n\n"); 
		while(1)
		{
			printf("�밴W��������Ķ������֣�\n");
			fflush(stdin);
			scanf("%c", &w);
			
			if( w == 'W' ) 
			{
			W = rand() % 100;
			printf("��Ķ���W�������ǣ�%d\n\n", W);
			break; 
			}
			else 
			{
			printf("error; �밴W��; \n\n");
			continue; 
			}
		}
	
		while(1)
		{
			printf("�밴G�����������Ķ������֣�\n");
			fflush(stdin);
			scanf("%c", &g);
			
			if( g == 'G' )
			{
			Wb = rand() % 10 + 45;
			printf("�����Ķ���Wb�������ǣ�%d\n\n", Wb); 
			break;
			}
			else 
			printf("error; �밴G��; \n\n");
			continue;
		}
		
			fflush(stdin);
			if( W < Wb )
			{
			printf("���������壬����ʧ�ܣ�\n");
			}
			else 
			{
			printf("���ɹ��������� O ����������ʳɹ�����\n");	
			}
			break;
	}
	case 'C':
	{
		printf("\n��ʼ���ʽ������\n������C��������C������;ת��ת�̽���O����ʼ������ʣ�\n�������������ִ��ڻ�������������ֵĴ�С�������O������֮������Σ�գ�\n\n"); 
		while(1)
		{
			printf("�밴W��������Ķ������֣�\n");
			fflush(stdin);
			scanf("%c", &w);
			
			if( w == 'W' ) 
			{
			W = rand() % 100;
			printf("��Ķ���W�������ǣ�%d\n\n", W);
			break; 
			}
			else 
			{
			printf("error; �밴W��; \n\n");
			continue; 
			}
		}
	
		while(1)
		{
			printf("�밴G�����������Ķ������֣�\n");
			fflush(stdin);
			scanf("%c", &g);
			
			if( g == 'G' )
			{
			Wc = rand() % 10 + 60;
			printf("�����Ķ���Wa�������ǣ�%d\n\n", Wc); 
			break;
			}
			else 
			printf("error; �밴G��; \n\n");
			continue;
		}
		
			fflush(stdin);
			if( W < Wc )
			{
			printf("���⵽����������ʧ�ܣ���\n");
			}
			else 
			{
			printf("���ɹ��������� O ����������ʳɹ�����\n");	
			}
			break;
	}
	case 'D':
	{
		printf("\n��ʼ���ʽ������\n������D��������D������;ת��ת�̽���O����ʼ������ʣ�\n�������������ִ��ڻ�������������ֵĴ�С�������O������֮������Σ�գ�\n\n"); 
		while(1)
		{
			printf("�밴W��������Ķ������֣�\n");
			fflush(stdin);
			scanf("%c", &w);
			
			if( w == 'W' ) 
			{
			W = rand() % 100;
			printf("��Ķ���W�������ǣ�%d\n\n", W);
			break; 
			}
			else 
			{
			printf("error; �밴W��; \n\n");
			continue; 
			}
		}
	
		while(1)
		{
			printf("�밴G�����������Ķ������֣�\n");
			fflush(stdin);
			scanf("%c", &g);
			
			if( g == 'G' )
			{
			Wd = rand() % 10 + 10;
			printf("�����Ķ���Wd�������ǣ�%d\n\n", Wd); 
			break;
			}
			else 
			printf("error; �밴G��; \n\n");
			continue;
		}
		
			fflush(stdin);
			if( W < Wd )
			{
			printf("��������ʧ������ʧ�ܣ���\n");
			}
			else 
			{
			printf("���ɹ��������� O ����������ʳɹ�����\n");	
			}
			break;
	}
	case 'N':
	{
	printf("����ʧ��!\n");	break;
	}
	default: printf("������ɣ��ȳ����ʣ�\n");
	}

	
 }
 
 	/*����IF�����ѡ�� 
	 if(flag == 1)
	printf("����ʧ��!\n");
	else if(flag == 'A')
	{
		W = rand() % 100;
		Wa = rand() % 10 + 80;
		if( W < Wa )
		printf("�����ױ�ը������ʧ�ܣ���\n");
		else 
		printf("���ɹ��������� O ����������ʳɹ�����");
	}
	else if(flag == 'B')
	{
		W = rand() % 100;
		Wb = rand() % 10 + 45;
		if( W < Wb )
		printf("���������壬����ʧ�ܣ���\n");
		else 
		printf("���ɹ��������� O ����������ʳɹ�����");
	}
	else if(flag == 'C')
	{
		W = rand() % 100;
		Wc = rand() % 10 + 60;
		if( W < Wc )
		printf("���⵽����������ʧ�ܣ���\n");
		else 
		printf("���ɹ��������� O ����������ʳɹ�����");
	}
	else if(flag == 'D')
	{
		W = rand() % 100;
		Wd = rand() % 10 + 10;
		if( W < Wd )
		printf("�����ױ�ը������ʧ�ܣ���\n");
		else 
		printf("���ɹ��������� O ����������ʳɹ�����");
	}
	else
	{
	printf("������ɣ��ȳ����ʣ�");
	}*/

	
