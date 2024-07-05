#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, j, k, m, n, size;

  printf("input size: ");  //输入大小提示
  scanf("%d", &size);      //输入大小
  if (size <= 0 || size % 2 == 0)  //如果为小于或等于0的数或为偶数
  {
	 printf("the size is error!\n");  //显示大小错误
	 exit(-1);                        //程序结束
  }
  
  for (i = 1; i <= size; i++)  //控制行数
  {
	n = (i <= (size+1)/2) ? i : size-i+1;   //每行中"*"号的个数
	n = 2 * n - 1;
	m = (size - n) / 2 + 15;  //每行打印"*"之前应打印的空格数
	for (k = 1; k <= m; k++)  //打印每行前面的空格
		printf(" ");
    for (j = 1; j <= n; j++)  //打印每行的"*"
	    printf("*");
	printf("\n");            //打印一行后，回车换行
  }
  return 0;
}
