#include <stdio.h>
int main()
{
	int a[2][3]={{1,2,3},{4,5,6}};
	printf("a[1][2] %d\n", a[1][2]);
	printf("*(a[1]+2) %d\n", *(a[1]+2));
	printf("*(*(a+1)+2) %d\n", *(*(a+1)+2));
	printf("%d\n", &a[1][2]);
	printf("%d\n", a[1]+2);
	printf("%d\n", *(a+1)+2);
	printf("a %d\n", a);
	printf("a %d\n", &a);
	printf("%d\n", a[0]);
	printf("%d\n", a[0][0]);
	printf("a+1 %d\n", a+1);
	printf("%d\n", a[1]);
	printf("%d\n", &a[1]);
	printf("%d\n", a+2);
	printf("%d\n", *(a+1));
	
	printf("a+1 %d\n", a+1);
	printf("%d\n", (a+1)+2);printf("%d\n", *((a+1)+2));
	printf("%d\n", *(a+1)+2);printf("%d\n", *(*(a+1)+2));
	
	
 } 
