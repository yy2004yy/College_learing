/*This is my seventh C program*/
#include <stdio.h>
int main()
{
	float h, w, t;
	
	printf("请输入你的身高height（米），体重weight（千克），通过该程序可以计算出你的体指数t的值\n");
	
	printf("身高（米） h = ");
	
	scanf("%f", &h);
	
	printf("体重（千克） w = ");
	
	scanf("%f", &w);
	
	t = w / (h*h);
	
	printf("体指数 t = %f", t);
	
	return 0;
 } 
