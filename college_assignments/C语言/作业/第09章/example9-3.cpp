#include  <stdio.h>
	
int main()
{
  short int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
  short int i, j,*p;

  p = &a[0][0];   //也可写成p = a[0];  p指向二维数组a的第一个单元 
  for(i = 0; i < 2; i++)   //变量i控制行数
  {
    for(j = 0; j < 3; j++)  //变量j控制列数
      printf("a[%d][%d] = %d  ", i, j, *(p + i*3 + j));  //显示每个数组元素的值
    printf("\n");   //数组的每一行元素输出后换行
  } 
  return 0;
}
