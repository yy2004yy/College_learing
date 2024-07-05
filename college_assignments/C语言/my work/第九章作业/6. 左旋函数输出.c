#include <stdio.h>
#include <string.h>
int main()
{
	void left_rev(char s[], int *n);
	char str[100];
	int num;
	printf("please input a string: \n");
	gets(str);
	printf("please input a integer: \n");
	scanf("%d", &num);
	left_rev(str, &num);
	return 0;
}

void left_rev(char s[], int *n)
{
	char a[100];
	int i;
	for(i = 0; i < (strlen(s) - *n); i++)
	*(a + *n + i) = *(s + i);
	for(i = 0; i < *n; i++)
	*(a + i) = *(s + strlen(s) - *n + i);
	for(i = 0; i < strlen(s); i++)
	printf("%c", *(a+i));
}
