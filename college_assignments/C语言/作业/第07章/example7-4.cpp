#include <stdio.h>
#define  NUM   10

int main( )
{
  int a[NUM], i, j, k, t;

  printf ("input %d numbers: \n", NUM);
  for (i = 0; i < NUM; i++)       //输入NUM个整数
     scanf ("%d", &a[i]);

  for (i = 0; i < NUM - 1; i++)  //选择排序（升序）
  {
    k = i;        //k为当前最小数的下标，初始值设为i
    for (j = i+1; j < NUM; j++)   //查找比a[k]小的数的下标放入k中
      if (a[k] > a[j])  //存在比a[k]小的数a[j]
        k = j;       //更改最小数的下标值
    if (k != i)   //如果最小数的下标有更改，将最小数a[k]与a[i]交换
    {
      t = a[i];
      a[i] = a[k];
      a[k] = t;
    }
  }

  printf ("the sorted numbers:\n");  //输出排好序的数据
  for (i = 0; i < NUM; i++)
    printf ("%d ", a[i]);
  return 0;
}
