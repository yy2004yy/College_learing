#include <stdio.h>
int main()
{
	int run_year(int *month, int *day);
	int judge_leap(int *yearp);
	int nor_year(int *month, int *day);
	void run_yearcnt(int *days);
	void nor_yearcnt(int *days);
	
	int year, month, day, days;
	printf("请输入年份："); 
	scanf("%d", &year);
	printf("请输入月份："); 
	scanf("%d", &month);
	printf("请输入日期："); 
	scanf("%d", &day);
	
	if(judge_leap(&year) == 1)//闰年 
	printf("%d年%d月%d日是该年份的第%d天。", year, month, day, run_year(&month, &day));	
	else
	printf("%d年%d月%d日是该年份的第%d天。", year, month, day, nor_year(&month, &day));	
	
	printf("\n请输入年份："); 
	scanf("%d", &year);
	printf("请输入第几天："); 
	scanf("%d", &days);
	
	if(judge_leap(&year) == 1)//闰年 
	run_yearcnt(&days);
	else
	nor_yearcnt(&days);	
	
	return 0;
}

int judge_leap(int *yearp)//判断闰年 
{
	int leap = 0; 
	if((*yearp % 4 == 0 && *yearp % 100 != 0)||(*yearp % 400 == 0))
	leap = 1;//闰年为leap = 1； 
	else 
	leap = 0;
	
	return (leap);
 } 
 
int run_year(int *month, int *day)//计算闰年的第几天 
{
	int number = 0, i;
	int mon[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//闰年2月有29天 
	for(i = 1; i < *month; i++)
	number = number + *(mon + i);
	number = number + *day;
	return (number);
 } 
 
int nor_year(int *month, int *day)//计算非闰年的第几天 
{
	int number = 0, i;
	int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//非闰年2月有28天 
	for(i = 1; i < *month; i++)
	number = number + *(mon + i);
	number = number + *day;
	return (number);
 } 
 
void run_yearcnt(int *days)
{
	int i, month = 0, day, sum;
	sum = *days;
	int mon[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//闰年2月有29天 
	for(i = 1; ; i++)
	{
		*days = *days - *(mon+i);
		if(*days > 0)
		month++;
		else
		break;
	}
	day = *days + *(mon+i);
	printf("该年份的第%d天是该年的第%d月第%d日。", sum, month + 1, day);
}
 
void nor_yearcnt(int *days)
{
	int i, month = 0, day, sum;
	sum = *days;
	int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//非闰年2月有28天 
	for(i = 1; ; i++)
	{
		*days = *days - *(mon+i);
		if(*days > 0)
		month++;
		else
		break;
	}
	day = *days + *(mon+i);
	printf("该年份的第%d天是该年的第%d月第%d日。", sum, month + 1, day);
}
 
 
 
 
 
 
 
 
 
 
 
