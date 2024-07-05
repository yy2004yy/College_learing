#include <stdio.h> 
int main()
{
	int i;
	char n;
	
	for (n = 33	, i = 1; n <= 62; n++)
	{
		printf("%c  ", n);
		
		if(i%10==0)
		printf("\n");
		i++;
		
	}

	return 0;
	
}
