#include <stdio.h>

int main ( )
{
    char ch;
    int n1, n2, n3, n4;
    n1=0;n2=0;n3=0;n4=0; 
    
	printf("������һ��Ӣ���ַ�����ͳ�Ƹ��ַ�����ĸ���;\n");//ͳ��һ��Ӣ����ĸ�������и����ַ��ĸ���
    printf("��������ַ���Ϊ��");
    
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
    
    printf("������Ӣ����ĸ�ĸ���Ϊ��%d\n", n2);
	printf("�����Ŀո�ĸ���Ϊ��%d\n", n3);
	printf("���������ֵĸ���Ϊ��%d\n", n1);
    printf("���������������ַ��ĸ���Ϊ��%d\n", n4);
    
    return 0;
}
