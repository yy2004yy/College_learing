#include <stdio.h>
#include <string.h> 
int n1 = 0, n2 = 0, n3 = 0, n4 = 0, c;
int main()
{
	int sta(char c, int *n1, int *n2, int *n3, int *n4);

	char str[1000];
	
	printf("������һ��Ӣ���ַ�����ͳ�Ƹ��ַ�����ĸ���;\n");
    printf("��������ַ���Ϊ��");
    
    do{
	c = getchar();
	sta(c, &n1, &n2, &n3, &n4);
	}while(c != '\n');
	
	printf("������Ӣ����ĸ�ĸ���Ϊ��%d\n", n2);
	printf("�����Ŀո�ĸ���Ϊ��%d\n", n3);
	printf("���������ֵĸ���Ϊ��%d\n", n1);
    printf("���������������ַ��ĸ���Ϊ��%d\n", n4);
    
    return 0;
 }  
 
int sta(char c, int *N1, int *N2, int *N3, int *N4)
{
	int i;
	N1 = &n1; N2 = &n2; N3 = &n3; N4 = &n4;
	
		if( '0' <= c && c <= '9')
		{
            (*N1)++;
            return(*N1); 
        }
        
		else if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		{
            (*N2)++;
            return (*N2);
        }
        
		else if(c == ' ')
		{
            (*N3)++;
            return (*N3);
        }
        
        else
        {
        	if( c == '\n')
			{
			*N4 = *N4;
			return (*N4);
			}
			else 
            {
			(*N4)++;
			return (*N4);
			}
        }
}

