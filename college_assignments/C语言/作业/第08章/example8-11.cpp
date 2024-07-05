#include <stdio.h>

int take[5], n = 0;
int like[5][5] = { {0,0,1,1,0}, {1,1,0,0,1}, {0,1,1,0,1}, {0,0,0,1,0}, {0,1,0,0,1} };
int book[5] = {0,0,0,0,0};

void Try(int i);

int main()
{
  Try(0);
  return 0;
}

void Try(int i)
{
  int j, k;

  for(j = 0; j <=4; j++)     //j代表书号
  {
	if (like[i][j] > 0 && book[j] == 0)  //i喜欢j书，且j书未被分走
	{
	  take[i] = j;   //j书分给i
	  book[j] = 1;   //记录j书已分
	  if (i == 4)    //如果i==4，输出分书方案
	  {
		n++;         //方案数加1
		printf("===第%d个方案===\n", n);  //输出方案号
		for(k = 0; k <=4; k++)      //输出分书方案
			printf("%d号书分给%c\n", take[k], 'A'+k);
		printf("\n");   //换行
	  }
	  else             //如果i!=4，继续给下一人分书
		  Try(i+1);    //递归调用Try(i+1)
	  book[j] = 0;     //记录j书待分
	}   
  }
}