#include <stdio.h>

int main()
{
  char  c;

  while(1)
  { 
	c = getchar();              //��ȡһ���ַ�
	if ( c >= 'a' && c <= 'z')  //��Сд��ĸ
	   putchar(c - 'a' + 'A');  //������д��ĸ
	else       //����Сд��ĸ
	   break;  //ѭ���˳�
   }
  return 0;
}
