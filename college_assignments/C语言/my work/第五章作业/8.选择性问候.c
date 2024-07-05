#include <stdio.h>
#include <conio.h>
int main ()
{
	int a;
	
	printf("*****Time*****\n");
	printf("  1 morning\n");
	printf("  2 afternoon\n");
	printf("  3 evening\n");
	printf("Please enter your choice: \n");
	
	scanf("%d", &a);
	
	switch(a)
	{
	case 1: printf("Good morning!\n"); break;
	case 2: printf("Good afternoon!\n"); break;
	case 3: printf("Good evening!\n"); break;
	default: printf("Selection error!\n");
	}
	
	return 0; 
	
}
