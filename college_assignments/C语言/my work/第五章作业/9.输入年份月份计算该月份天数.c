#include <stdio.h>
int main()
{
	int year, month, leap;
	printf("��ݣ�"); 
	scanf("%d", &year);
	printf("�·ݣ�"); 
	scanf("%d", &month);
	
	if((year % 4 == 0)&&(year % 100 != 0)||(year % 400 == 0))
	    leap = 1;//leap = 1 ��ʾ��һ��Ϊ���� 
	else 
	    leap = 0; 

	if (leap == 1)
		switch(month)
		{
			case 1: printf("���·�������31\n"); break;
			case 2: printf("���·�������29\n"); break;
			case 3: printf("���·�������31\n"); break;
			case 4: printf("���·�������30\n"); break;
			case 5: printf("���·�������31\n"); break;
			case 6: printf("���·�������30\n"); break;
			case 7: printf("���·�������31\n"); break;
			case 8: printf("���·�������31\n"); break;
			case 9: printf("���·�������30\n"); break;
			case 10: printf("���·�������31\n"); break;
			case 11: printf("���·�������30\n"); break;
			case 12: printf("���·�������31\n"); break;
			default : printf("Data error!\n");
		
			}	
	
	else
		switch(month)
		{
			case 1: printf("���·�������31\n"); break;
			case 2: printf("���·�������28\n"); break;
			case 3: printf("���·�������31\n"); break;
			case 4: printf("���·�������30\n"); break;
			case 5: printf("���·�������31\n"); break;
			case 6: printf("���·�������30\n"); break;
			case 7: printf("���·�������31\n"); break;
			case 8: printf("���·�������31\n"); break;
			case 9: printf("���·�������30\n"); break;
			case 10: printf("���·�������31\n"); break;
			case 11: printf("���·�������30\n"); break;
			case 12: printf("���·�������31\n"); break;
			default : printf("Data error!\n");
		
			}	
	
	return 0;
 } 
