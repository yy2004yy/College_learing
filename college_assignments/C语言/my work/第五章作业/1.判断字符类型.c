#include <stdio.h>
int main ()
{
	char c ;
	
	printf("Please input a character:");
	c = getchar();
	
	if (c < 0x20)
	printf("The character is a control character\n");
	
	else if(c >= '0' && c <= '9')
	printf("The character is a digit\n");
	
	else if(c >= 'A' && c <= 'Z')
	printf("The character is a capital letter\n");
	
	else if(c >= 'a' && c <= 'z')   
	printf("The character is a lower letter\n");
	
	else
	printf ("The character is other character\n");
	
	return 0;
	
 } 
