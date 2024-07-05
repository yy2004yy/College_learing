#include <stdio.h>
int main()
{
	int s1[5], i;
	for(i = 0; i < 5; i++)
	scanf("%d", s1 + i);
	for(i = 0; i < 5; i++)
	printf("%d ", *(s1 + i));
}
