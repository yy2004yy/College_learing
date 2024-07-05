#include <stdio.h>
int main()
{
	int a;
	char c;
	c = getchar(); 
	scanf("%x", &a);
	putchar(c);
	printf("%x", a); 
}
