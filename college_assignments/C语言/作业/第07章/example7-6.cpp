#include <stdio.h>

int main()
{ 
  int i, j, row = 0, col = 0, max;
  int a[3][4] = {{1, 2, 3, 4}, {9, 8, 7, 6}, {-10, 10, -5, 2}};  //定义数组并赋初值

  max = a[0][0];
  for (i = 0; i < 3; i++)
	 for (j = 0; j < 4; j++)
		if (a[i][j] > max)  //如果某元素大于max，就取代max的原值
		{
		  max = a[i][j];
		  row = i;          //记下此元素的行号
		  col = j;          //记下此元素的列号
		}
  printf("max = %d, row = %d, col = %d\n", max, row, col);
  return 0;
}
