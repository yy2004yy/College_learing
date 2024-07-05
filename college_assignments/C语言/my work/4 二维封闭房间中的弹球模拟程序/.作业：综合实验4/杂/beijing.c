#include <stdio.h>
int main()
{
	int i, j;
	for(i = 0; i < 79; i++)
	printf("-");
	printf("\n");
	
	for(j = 0; j < 24; j++)
	{
	printf("!");
	for(i = 0; i < 77; i++)
	printf(" ");
	printf("!\n");
	}
	
	for(i = 0; i < 79; i++)
	printf("-");
	printf("\0");
}

