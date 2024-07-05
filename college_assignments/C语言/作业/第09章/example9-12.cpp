#include <stdio.h>
#include <string.h>

void alltrim(char *psstr,char *pdstr);

int main()
{
  char *pstr, str[20];
  
  pstr = "  Good Bye!  ";

  printf("before alltrim: %s\n",pstr);
  alltrim(pstr,str);
  printf("after  alltrim: %s\n",str);
  return 0;
 }

void alltrim(char *psstr,char *pdstr)
{
  char *pstart,*pend;

  //将pstart指向左边第一个非空格字符的位置
  pstart = psstr;   
  while (*pstart == ' ')
	pstart++;

  //将pend指向右边第一个非空格字符的位置
  pend = pstart + strlen(pstart) - 1;  
  while (pend > pstart && *pend == ' ')
	pend--;

  //将pstart所指向的字符至pend所指向的字符拷贝到pdstr中
  while(pstart <= pend)
    *pdstr++ = *pstart++;
  *pdstr = '\0';   //加字符串结束标志0
}
