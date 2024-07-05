#include <stdio.h>
int main()
{
	char a[100];
	printf("%d\n", &a);
	printf("%d\n", a);
	printf("%d\n", a+1);
		
	int b[100];int *bp = b;
	printf("%d\n", &b);
	printf("%d\n", b);
	printf("%d\n", b+1);
	printf("%d\n", bp +1);
	return 0;

}
