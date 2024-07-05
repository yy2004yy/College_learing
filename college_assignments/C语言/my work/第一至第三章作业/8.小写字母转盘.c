/*This is my eighth C program*/
#include <stdio.h>
int main()
{
	char a, b, c;
	printf("输入一个小写英文字母字符，我们会给出其前驱字符和后置字符\n");
	printf("请输入小写英文字符：");
	scanf("%c" , &a );
	
    
	if ( a =='a' )
{
	printf("前驱字符：z\n后置字符：b");
	}
	
	
	else if ( a =='z' )
{
	printf("前驱字符：y\n后置字符：a");
	}
	
	
	else
{
	b = a + 1;
	c = a - 1;
	printf("前驱字符：%c\n后置字符：%c", c, b);
	}
	
    return 0;
 } 
