#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( )
{
  int i, n, p, q, flagp, flagq;

  printf("please input n: ");
  scanf("%d", &n);            //输入一偶数
  if (n < 4 || n % 2 != 0)   //如果该数不是偶数
  {
    printf("input data error!\n");  //显示输入数据错
	exit(-1);  //程序结束
  }

  p = 1;
  do 
  {
    p++;
    q = n - p;
    
	//判断p是否为素数
    flagp = 1;
    for (i = 2; i <= (int) sqrt(p); i++)
	{
      if (p % i == 0)
	  {
        flagp = 0;
        break;
	  }
	}

	//判断q是否为素数
    flagq = 1;
    for (i = 2; i <= (int)sqrt(q); i++)
    {
      if (q % i == 0)
	  {
        flagq = 0;
        break ;
	  }
    }
  } while (flagp * flagq == 0);  //当p、q中有一个不为素数时继续循环

  printf("%d = %d + %d\n", n, p, q);  //显示结果
  return 0;
}
