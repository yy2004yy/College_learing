#include <stdio.h>
#define PI 3.14
int main()
{
	int r;
	float S, C;
	scanf("%d", &r); 
	S = PI*r*r;
	C = 2*PI*r;
	printf("S = %f, C = %f", S, C);
	return 0;
	
}
