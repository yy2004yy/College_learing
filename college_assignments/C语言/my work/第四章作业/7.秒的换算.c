#include <stdio.h>
int main()
{
	int t, days, hour, min, second, p;
	
	printf("��ĳҹ��ҹ�賿��㿪ʼ�������Ѿ�����t��\n");
	printf("t = "); 
	scanf("%d", &t);
	
	days = t / 86400;
	p = t - days * 86400;
	hour = p / 3600;
	min = (p - hour*3600) / 60;
	second = p - hour*3600 - min*60;  
	
	printf("�������Ѿ�����%d��\n", days );
	printf("������%dʱ%d��%d��\n", hour, min, second);
	
	return 0;
 } 
