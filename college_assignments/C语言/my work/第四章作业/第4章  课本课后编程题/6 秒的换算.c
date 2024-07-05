#include <stdio.h>
int main()
{
	int t, days, hour, min, second, p;
	
	printf("从某夜午夜凌晨零点开始到现在已经过了t秒\n");
	printf("t = "); 
	scanf("%d", &t);
	
	days = t / 86400;
	p = t - days * 86400;
	hour = p / 3600;
	min = (p - hour*3600) / 60;
	second = p - hour*3600 - min*60;  
	
	printf("到现在已经过了%d天\n", days );
	printf("现在是%d时%d分%d秒\n", hour, min, second);
	
	return 0;
 } 
