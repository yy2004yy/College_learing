#include <stdio.h>

int main()
{ 
  int i, j, row = 0, col = 0, max;
  int a[3][4] = {{1, 2, 3, 4}, {9, 8, 7, 6}, {-10, 10, -5, 2}};  //�������鲢����ֵ

  max = a[0][0];
  for (i = 0; i < 3; i++)
	 for (j = 0; j < 4; j++)
		if (a[i][j] > max)  //���ĳԪ�ش���max����ȡ��max��ԭֵ
		{
		  max = a[i][j];
		  row = i;          //���´�Ԫ�ص��к�
		  col = j;          //���´�Ԫ�ص��к�
		}
  printf("max = %d, row = %d, col = %d\n", max, row, col);
  return 0;
}
