#include <stdio.h>

void mergestr(char s1[], char s2[], char s3[]);

int main()
{
	char str1[] = {"hello "};
	char str2[] = {"C language!"};
	char str3[40];

	mergestr(str1,str2,str3);
	printf("%s\n",str3);
	return 0;
}

void mergestr(char s1[], char s2[], char s3[])  
{
  int i, j;
  
  for(i = 0; s1[i] != '\0'; i++)
	s3[i] = s1[i];
  for(j = 0; s2[j] != '\0'; j++)
	s3[i+j] = s2[j];
  s3[i+j] = '\0';
}