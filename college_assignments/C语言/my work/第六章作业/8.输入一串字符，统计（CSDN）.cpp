#include <stdio.h>
#include "string.h"
int main ( )
{

    printf("������һ��Ӣ���ַ�����ͳ���䵥�ʵĸ�����");//   ͳ��һ��Ӣ����ĸ�������еĵ��ʵĸ�����
    char ch[]={};
    gets(ch);
    printf("��������ַ���Ϊ��%s\n",ch);
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
    
    printf("%s������Ӣ�ĵ��ʵĸ���Ϊ��%d\n", n1);
    printf("%s������Ӣ�ĵ��ʵĸ���Ϊ��%d\n",ch,count);
}
