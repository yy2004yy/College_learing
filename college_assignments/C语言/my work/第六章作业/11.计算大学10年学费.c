#include <stdio.h>
#include <math.h>
int main()
{
	double cur, total;
	int year;
	year = 1;cur = 10000; total = 0;
	
	printf("Year\tCurrent Tuition($)\tToatal Tuition($)\t\n");
	
	while( year <= 10 )
	{
		total = cur + cur*pow(1.05, 1) + cur*pow(1.05, 2) + cur*pow(1.05, 3);
		printf("%4d %21.2lf %22.2lf\n", year, cur, total);
		cur = cur*1.05;
		year++;
	 } 
	
	return 0;
 } 
