#include <stdio.h>
int main()
{
	int run_year(int *month, int *day);
	int judge_leap(int *yearp);
	int nor_year(int *month, int *day);
	void run_yearcnt(int *days);
	void nor_yearcnt(int *days);
	
	int year, month, day, days;
	printf("��������ݣ�"); 
	scanf("%d", &year);
	printf("�������·ݣ�"); 
	scanf("%d", &month);
	printf("���������ڣ�"); 
	scanf("%d", &day);
	
	if(judge_leap(&year) == 1)//���� 
	printf("%d��%d��%d���Ǹ���ݵĵ�%d�졣", year, month, day, run_year(&month, &day));	
	else
	printf("%d��%d��%d���Ǹ���ݵĵ�%d�졣", year, month, day, nor_year(&month, &day));	
	
	printf("\n��������ݣ�"); 
	scanf("%d", &year);
	printf("������ڼ��죺"); 
	scanf("%d", &days);
	
	if(judge_leap(&year) == 1)//���� 
	run_yearcnt(&days);
	else
	nor_yearcnt(&days);	
	
	return 0;
}

int judge_leap(int *yearp)//�ж����� 
{
	int leap = 0; 
	if((*yearp % 4 == 0 && *yearp % 100 != 0)||(*yearp % 400 == 0))
	leap = 1;//����Ϊleap = 1�� 
	else 
	leap = 0;
	
	return (leap);
 } 
 
int run_year(int *month, int *day)//��������ĵڼ��� 
{
	int number = 0, i;
	int mon[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//����2����29�� 
	for(i = 1; i < *month; i++)
	number = number + *(mon + i);
	number = number + *day;
	return (number);
 } 
 
int nor_year(int *month, int *day)//���������ĵڼ��� 
{
	int number = 0, i;
	int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//������2����28�� 
	for(i = 1; i < *month; i++)
	number = number + *(mon + i);
	number = number + *day;
	return (number);
 } 
 
void run_yearcnt(int *days)
{
	int i, month = 0, day, sum;
	sum = *days;
	int mon[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//����2����29�� 
	for(i = 1; ; i++)
	{
		*days = *days - *(mon+i);
		if(*days > 0)
		month++;
		else
		break;
	}
	day = *days + *(mon+i);
	printf("����ݵĵ�%d���Ǹ���ĵ�%d�µ�%d�ա�", sum, month + 1, day);
}
 
void nor_yearcnt(int *days)
{
	int i, month = 0, day, sum;
	sum = *days;
	int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//������2����28�� 
	for(i = 1; ; i++)
	{
		*days = *days - *(mon+i);
		if(*days > 0)
		month++;
		else
		break;
	}
	day = *days + *(mon+i);
	printf("����ݵĵ�%d���Ǹ���ĵ�%d�µ�%d�ա�", sum, month + 1, day);
}
 
 
 
 
 
 
 
 
 
 
 
