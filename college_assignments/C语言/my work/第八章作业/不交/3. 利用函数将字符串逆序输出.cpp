#include <stdio.h>
#include <string.h>
int main()
{
	int inv(char str[]);
	int i;
	char str[100];
	for(i = 0; str[i] == '\n'; i++)
	scanf("%c", &str[i]);
	inv(str);
 } 
 
int inv(char str[100])
{
	int len, i, j;
	
	printf("������һ���ַ�����\n");
	gets(str);
	len = strlen(str);
	
	printf("���ַ������������Ϊ��\n");
	for(i = 0; i <= len; i++)
	printf("%c", str[len - i - 1]);

}
