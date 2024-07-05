#include <stdio.h>
#include <math.h>
int main() 
{
	double n, e, N, i;
	int cnt;
	
	e = 1 + 1/1;
	n = 1;
	i = 1;
	cnt = 2;
	   
	while( fabs(n) > 1e-5 )
	{
		n = n*( 1.0 / (i + 1) );
		e = e + n;
		i++;
		cnt++;
		}
		
	printf("e = %lf\n", e);	
	printf("总共累计了%d项", cnt);	
	
}
