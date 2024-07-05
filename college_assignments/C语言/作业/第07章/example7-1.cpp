#include <stdio.h>
#include <memory.h>

int main( void)
{  
  char ch;  
  int  num[26], i;

  memset(num, 0, 26*sizeof(int));    //初始化数组num
  while ((ch = getchar( )) != '\n')  //输入字符串，判断统计
    if (ch >= 'A' && ch <= 'Z')      //是否为大写字母
       num[ch-'A']++;

  for(i = 0; i < 26; i++)  //输出结果
  { 
   if (i % 9 == 0)
      printf("\n");
   printf("%c(%d) ", 'A'+i, num[i]);
  }
  printf("\n");
  return 0;
}
