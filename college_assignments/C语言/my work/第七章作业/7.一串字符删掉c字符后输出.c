#include <stdio.h>
#include <string.h>
int main ()
{
	char str[100], len, i, j;
	
	printf("������һ���ַ�����\n");
	gets(str);
	
	len = strlen(str);//len��Ϊ�����ַ�����ĳ���
	//Ҳ�����ǣ�for(len = 0; getchar() != '\0'; len++)
	
	for(i = 0; i <= len; i++)
	{
		if(str[i] == 'c' || str[i] == 'C')
		{
			for(j = i; j <= len + 1; j++)
			str[j] = str[j+1];
		}
	 } 
	printf("ɾȥc��C֮����ַ�����Ϊ��\n"); 
	puts(str);
	return 0;
}
