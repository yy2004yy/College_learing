#include <stdio.h>
#include <conio.h>
#include <string.h>

#define N  20   //数字字符的个数

void beep();
void GetNumberStr(char s[]);
void AddNumberStr(char a[],char b[],char c[]);
char AddChar(char ch1, char ch2);
void LeftTrim(char str[]);

int tag = 0;   //进位标志

int main()
{
  char a[N+1] = {0}, b[N+1] = {0}, c[N+2];
  
  //输入被加数a、加数b
  printf("a = ");
  while(strlen(a) == 0)
    GetNumberStr(a);
  printf("\nb = ");
  while(strlen(b) == 0)
    GetNumberStr(b);

  //计算和数c
  AddNumberStr(a,b,c);

  //显示计算结果
  printf("\na + b = %s \n",c);
  return 0;
}

void GetNumberStr(char s[])  //读取数字字符串
{
  int i = 0;
  char ch;
  
  while(1)
  {
    ch = getch();
    if (ch == '\r')  //回车符，退出  
  	   break;
	if (ch == '\b')  //退格符
	{
	  if (i > 0)  
	  {
		printf("%c %c",ch,ch);
		i--;
	  }
	  else
		beep();
	  continue;
    }
	if (ch < '0' || ch > '9')   //非数字字符
	{
	  beep();
      continue;
	}
	if (i < N)   //数字字符
	{
	  printf("%c",ch);
	  s[i++] = ch;
	}
	else
	  beep();
  }
  s[i] = '\0';  //置字符串结束标志
}

void beep()  //响铃
{
  printf("\07");
}

//计算两个数字字符串之和，放在c中
void AddNumberStr(char a[],char b[],char c[])
{
  int i,j,k;

  memset(c,' ',N+2);  //将C全部清空

  i = strlen(a) - 1;
  j = strlen(b) - 1;
  k = N;
  while(i >= 0 && j >= 0)  //将被加数与加数按照从右向左的顺序相加
    c[k--] = AddChar(a[i--],b[j--]);
  while(i >= 0)   //被加数没有加完
	c[k--] = AddChar(a[i--],'0');
  while(j >= 0)   //加数没有加完
	c[k--] = AddChar(b[j--],'0');
  if (tag == 1)   //最后有进位,将其放在和数的最高位
	 c[k] = '1';
  c[N+1] = '\0';  //置字符串结束标志
  LeftTrim(c);    //去掉字符串c左边的空格
}

//计算两个数字字符之和
char AddChar(char ch1, char ch2)
{
  char ch;

  ch = (ch1-0x30 + ch2-0x30) + tag;  //两数字字符所对应的数字与进位相加
  if (ch >= 10)  //结果大于10
  {
    tag = 1;  //有进位
	return(ch - 10 + 0x30);  //将个位数减10后加上0x30转换成其数字字符
  }
  else   //结果小于10
  {
	tag = 0;   //没进位
	return(ch + 0x30);  ////将和数加上0x30转换成其数字字符
  }
}

//去掉字符串左边的空格
void LeftTrim(char str[])
{
  int i;

  for(i = 0; str[i] == ' '; i++)  //查找第一个非空格字符的位置
	;
  strcpy(str,str+i);
}