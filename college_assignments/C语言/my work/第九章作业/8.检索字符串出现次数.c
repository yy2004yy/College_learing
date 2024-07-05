#include <stdio.h>
#include <string.h>
int main()
{
	int substring(char s1[], char s2[]);
	char sou[100], sub[100];
	printf("please input a Sourse string: \n");
	gets(sou);
	printf("please input a substring: \n");
	gets(sub);
	printf("The number of occurences of the substring is %d.\n", substring(sou, sub));
	return 0;
 } 
 
int substring(char s1[], char s2[])
{
	int i, j = 0, flag = 0, cnt = 0;
	for(i = 0; i < strlen(s1); i++)
	{
		if(s1[i] == s2[j]) 
		{
			flag =1;
			j++;
			cnt++;
		} 

		if(j == strlen(s1)-1) 
		j = 0;		
	}
	return (cnt);
}
