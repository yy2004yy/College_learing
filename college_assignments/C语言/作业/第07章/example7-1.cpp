#include <stdio.h>
#include <memory.h>

int main( void)
{  
  char ch;  
  int  num[26], i;

  memset(num, 0, 26*sizeof(int));    //��ʼ������num
  while ((ch = getchar( )) != '\n')  //�����ַ������ж�ͳ��
    if (ch >= 'A' && ch <= 'Z')      //�Ƿ�Ϊ��д��ĸ
       num[ch-'A']++;

  for(i = 0; i < 26; i++)  //������
  { 
   if (i % 9 == 0)
      printf("\n");
   printf("%c(%d) ", 'A'+i, num[i]);
  }
  printf("\n");
  return 0;
}
