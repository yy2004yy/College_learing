/*This is my eighth C program*/
#include <stdio.h>
int main()
{
	char a, b, c;
	printf("����һ��СдӢ����ĸ�ַ������ǻ������ǰ���ַ��ͺ����ַ�\n");
	printf("������СдӢ���ַ���");
	scanf("%c" , &a );
	
    
	if ( a =='a' )
{
	printf("ǰ���ַ���z\n�����ַ���b");
	}
	
	
	else if ( a =='z' )
{
	printf("ǰ���ַ���y\n�����ַ���a");
	}
	
	
	else
{
	b = a + 1;
	c = a - 1;
	printf("ǰ���ַ���%c\n�����ַ���%c", c, b);
	}
	
    return 0;
 } 
