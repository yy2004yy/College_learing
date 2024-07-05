#include <stdio.h>

int main()
{
  short int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
  short int (*p)[3];
  short int i, j;

  p = a;   // p指向二维数组a的第一行行地址 
  for (i = 0; i < 2; i++)   //变量i控制行数
  {
    for (j = 0; j < 3; j++)  //变量j控制列数
      printf("a[%d][%d] = %d  ", i, j, p[i][j]);  //显示每个数组元素的值
    printf("\n");   //数组的每一行元素输出后换行
  }
  
  p++;   // p指向二维数组a的第二行行地址
  for (j = 0; j < 3; j++) 
    printf("%d  ", p[0][j]);   //显示数组中第二行的元素值
  return 0;
}

