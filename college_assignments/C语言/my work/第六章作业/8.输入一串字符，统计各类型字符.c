#include <stdio.h>

int main ( )
{
    char ch;
    int n1, n2, n3, n4;
    n1=0;n2=0;n3=0;n4=0; 
    
	printf("请输入一行英文字符串，统计各字符种类的个数;\n");//统计一行英文字母中所含有各种字符的个数
    printf("你输入的字符串为：");
    
    do
	{
		ch = getchar();
		
        if( '0' <= ch && ch <= '9')
		{
            n1++;
        }
        
		else if(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
		{
            n2++;
        }
        
		else if(ch == ' ')
		{
            n3++;
        }
        
        else
        {
        	if( ch == '\n')
			n4 = n4;
			else 
            n4++;
        }
        
    }while(ch != '\n');
    
    printf("所含的英文字母的个数为：%d\n", n2);
	printf("所含的空格的个数为：%d\n", n3);
	printf("所含的数字的个数为：%d\n", n1);
    printf("所含的其他类型字符的个数为：%d\n", n4);
    
    return 0;
}
