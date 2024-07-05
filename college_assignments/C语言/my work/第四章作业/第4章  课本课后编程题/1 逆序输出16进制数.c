#include <stdio.h>
#include <math.h>
int main()
{
	int a;
	scanf("%4X", &a);
	int ch[4];
	ch[0] = a / pow(16, 3);
	ch[1] = (a - ch[0]*pow(16, 3) ) / pow(16, 2);
	ch[2] = (a - ch[0]*pow(16, 3) - ch[1]*pow(16, 2)) / 16;
	ch[3] = a % 16;
	printf("%X%X%X%X", ch[3], ch[2], ch[1], ch[0]);
	return 0;
}
