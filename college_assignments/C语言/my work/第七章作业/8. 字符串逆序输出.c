#include <stdio.h>
#include <string.h>
int main ()
{
	char str[100], len, i, j;
	
	printf("������һ���ַ�����\n");
	gets(str);
	len = strlen(str);
	
	printf("���ַ������������Ϊ��\n");
	for(i = 0; i <= len; i++)
	printf("%c", str[len - i - 1]);

}
