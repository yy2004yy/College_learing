#include <Stdio.h>
#include <math.h>
int main()
{
	float x = 0.1;
	
	if (fabs(x - 1/10.0) < 1e-6) printf("equal.\n");
	else printf("Not equal.\n"); 
	
}



