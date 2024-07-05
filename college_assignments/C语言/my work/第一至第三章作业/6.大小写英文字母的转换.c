/*This is my sixth C program*/
#include <stdio.h>
int main()
{
	char y , Y;
	 
	printf("输入一个小写英文字母，然后你会得到相应的大写字母\n");
	
	printf("小写字母：");
	
	scanf("%c", &y);
	
    Y = y - 32;
    
	printf("大写字母：%c\n", Y);
	
	return 0; 
 } 
