#include <stdio.h>
#include <string.h>
int main ()
{
	char str[100], len, i, j;
	
	printf("请输入一行字符串：\n");
	gets(str);
	len = strlen(str);
	
	printf("此字符串的逆序输出为：\n");
	for(i = 0; i <= len; i++)
	printf("%c", str[len - i - 1]);

}
