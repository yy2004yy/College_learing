#include <stdio.h>
#include <math.h>
#define  GNP  0.06
int main()
{
	int year = 10;
	float p0, p, k;
	
	p0 = pow((1 + GNP), year);
	p = p0 - 1;
	k = 100*p;
	
	printf("ʮ������������ֵ�������������%f%%.", k);
	return 0; 
	
}
