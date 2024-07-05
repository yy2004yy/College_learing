#include <stdio.h>
#include <string.h>
int main()
{
	void Strcat(char s1[], char s2[]);
	char dstStr[100], srcStr[100];
	printf("Please input a string: \n");
	gets(dstStr);
	printf("Please input another string: \n");
	gets(srcStr);
	printf("The new string is: \n");
	Strcat(dstStr, srcStr);
}

void Strcat(char s1[], char s2[])
{
	char str[100], i, j;
	for(i = 0; i < strlen(s1); i++)
	*(str + i) = *(s1 + i);
	for(j = 0; j <strlen(s2); j++)
	*(str + i + j) = *(s2 + j);
	printf("%s", str);
}
