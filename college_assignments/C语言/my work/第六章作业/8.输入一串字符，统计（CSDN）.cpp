#include <stdio.h>
#include "string.h"
int main ( )
{

    printf("请输入一行英文字符串，统计其单词的个数：");//   统计一行英文字母中所含有的单词的个数：
    char ch[]={};
    gets(ch);
    printf("你输入的字符串为：%s\n",ch);
    int i =0 ,count=0,word=0,n1, n2, n3;
    int n[100]=0;
    for (; ch[i]!='\0'; i++) 
	{
        if( '0' <=ch[i] <= '9')
		{
            n1++;
            continue;
        }
		else if('a' <=ch[i] <= 'z' || 'A' <=ch[i] <= 'Z')
		{
            n2++;
            continue;
        }
        
		else if(ch[i] == ' ');
		{
            n3++;
            continue;
        }
        
        else
        {
            n4++;
            continue;
        }
        
        
        
    }
    
    printf("%s所含的英文单词的个数为：%d\n", n1);
    printf("%s所含的英文单词的个数为：%d\n",ch,count);
}
