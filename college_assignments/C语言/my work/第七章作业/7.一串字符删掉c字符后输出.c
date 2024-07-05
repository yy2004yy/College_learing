#include <stdio.h>
#include <string.h>
int main ()
{
	char str[100], len, i, j;
	
	printf("请输入一行字符串：\n");
	gets(str);
	
	len = strlen(str);//len即为整个字符数组的长度
	//也可以是：for(len = 0; getchar() != '\0'; len++)
	
	for(i = 0; i <= len; i++)
	{
		if(str[i] == 'c' || str[i] == 'C')
		{
			for(j = i; j <= len + 1; j++)
			str[j] = str[j+1];
		}
	 } 
	printf("删去c或C之后的字符数组为：\n"); 
	puts(str);
	return 0;
}
