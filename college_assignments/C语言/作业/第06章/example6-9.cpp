#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( )
{
  int i, n, p, q, flagp, flagq;

  printf("please input n: ");
  scanf("%d", &n);            //����һż��
  if (n < 4 || n % 2 != 0)   //�����������ż��
  {
    printf("input data error!\n");  //��ʾ�������ݴ�
	exit(-1);  //�������
  }

  p = 1;
  do 
  {
    p++;
    q = n - p;
    
	//�ж�p�Ƿ�Ϊ����
    flagp = 1;
    for (i = 2; i <= (int) sqrt(p); i++)
	{
      if (p % i == 0)
	  {
        flagp = 0;
        break;
	  }
	}

	//�ж�q�Ƿ�Ϊ����
    flagq = 1;
    for (i = 2; i <= (int)sqrt(q); i++)
    {
      if (q % i == 0)
	  {
        flagq = 0;
        break ;
	  }
    }
  } while (flagp * flagq == 0);  //��p��q����һ����Ϊ����ʱ����ѭ��

  printf("%d = %d + %d\n", n, p, q);  //��ʾ���
  return 0;
}
