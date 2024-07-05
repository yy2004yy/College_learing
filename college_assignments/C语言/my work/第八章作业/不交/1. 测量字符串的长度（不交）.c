#include <stdio.h>
int main()
{
	int str_len(char str[100]);
	char str[100];
	int cnt;
	scanf("%s", str);
	printf("The length of the string is %d\n", str_len(str));
}

int str_len(char str[100])
{
	int i, cnt = 0;
	for(i = 0; str[i] != '\0'; i++)
	cnt++;
	return (cnt);
 }
