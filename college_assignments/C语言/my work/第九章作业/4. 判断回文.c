#include <stdio.h>
#include <string.h>
int main()
{
	int Huiwen(char s[]);
	char str[100];
	printf("please input a string: \n");
	gets(str); 
	if(Huiwen(str) == 1)
	printf("Palinfrome!");
	else
	printf("Normal!");
 }

int Huiwen(char s[])
{
	int flag = 0, i;
	for(i = 0; i <= strlen(s)-1; i++)	
	{
		if(*(s+i) == *(s+strlen(s)-1-i))
		flag = 1;
		else
		{
		flag = 0;
		break;
		}
	}
	return(flag);
 } 
