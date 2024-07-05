#include <stdio.h>
#include <string.h>
int strLoc(char s1[100], char s2[100]);
int main()
{
	char str1[100], str2[100];
	
	printf("Please enter a string as the entirety: \n");
	gets(str2);
	fflush(stdin);
	printf("Please enter a string as the target: \n");
	gets(str1);
	
	printf("The location of the target string is: %d", strLoc(str1, str2));
	return 0;
 } 
 
int strLoc(char s1[], char s2[])
{
	int flag = 0, i, j, cnt;
	
	for(i = 0, j = 0; j < strlen(s1) && i < strlen(s2); i++)
	{
		if(s2[i] == s1[j])
		{
			j++;
			flag = 1;
			cnt = i;
		}
		else
		{
			j = 0;
			flag = 0;
		}

		if(i == s2[strlen(s2)-1] || j < strlen(s1))
		flag = 0;
	 }
	
	cnt = cnt - strlen(s1) + 1;
	if(flag == 1)  
	return(cnt);
	else
	return(-1);
} 
