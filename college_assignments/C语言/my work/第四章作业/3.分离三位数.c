#include<stdio.h>
#include<string.h>
int main ()
{
	int x,a1,a2,a3,a4,t,a,cnt;
	
	printf("Please input a four-digit number x:");
	scanf("%d", &x);
	cnt = 0;
	
	do {
		
		a1 = x / 1000 ;
		a2 = (x - a1*1000) / 100 ;
		a3 = (x - a1*1000 - a2*100)/10 ;
		a4 = x - a1*1000 - a2*100 - a3*10;
		
		if(a1<a2){t=a1;a1=a2;a2=t;}
		if(a1<a3){t=a1;a1=a3;a3=t;}
		if(a1<a4){t=a1;a1=a4;a4=t;}
		if(a2<a3){t=a2;a2=a3;a3=t;}
		if(a2<a4){t=a2;a2=a4;a4=t;}
		if(a3<a4){t=a3;a3=a4;a4=t;}
		
		a = a1*1000 + a2*100 + a3*10 + a4*1; 
		
		if (x>=a)
			x = x - a;
		else 
			x = a - x;
		
		cnt++;
		
	
		
	}   while(x != 6174);
	
		printf("´ÎÊıÎª:%d", cnt);
	
	return 0;
	
} 
