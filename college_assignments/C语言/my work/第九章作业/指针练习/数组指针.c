#include <stdio.h>
int main()
{
	int a[2][2] = {{1,5},{2,8}};
	int (*p)[2];
	p = a;
	printf("%d %d", a[0][1], p[0][1]);
}
