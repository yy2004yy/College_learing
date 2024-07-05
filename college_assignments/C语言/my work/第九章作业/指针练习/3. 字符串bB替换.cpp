#include <stdio.h>
#include <string.h>
int main()
{
	int replace(char s[]);
	char str[100], count;
	printf("Please input a string: \n");
	gets(str);
	count = replace(str);
	printf("\nThe number of replacements is %d: ", count);
}
int replace(char s[])
{
	int i, cnt = 0;
	for(i = 0; i < strlen(s); i++)
	{
		if(*(s+i) == 'b')
		{
			*(s+i) = 'c';
			cnt++;
		}
		if(*(s+i) == 'B')
		{
			cnt++;
			*(s+i) = 'C';
		}
	}
	printf("The new string is: \n");
	for(i = 0; i < strlen(s); i++)
	printf("%c", *(s+i));
	return (cnt);
}
