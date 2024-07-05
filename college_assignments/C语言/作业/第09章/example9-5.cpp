#include  <stdio.h>

int main()
{
  int i, j, t;
  int a, b, c, d, e;
  int *p[5] = {&a, &b, &c, &d, &e};

  scanf("%d,%d,%d,%d,%d", p[0], p[1], p[2], p[3], p[4]);  //对a,b,c,d,e赋值
  for(i = 0; i < 4; i++)       //利用冒泡法排序
    for(j = i + 1; j < 5; j++)
      if (*p[i] > *p[j])      //交换p[i]、p[j]所指向的变量值
      {
        t = *p[i];
        *p[i] = *p[j];
        *p[j] = t;
      }
  for(i = 0; i < 5; i++)      //显示排序后的结果
    printf("%d  ", *p[i]);
  return 0;
}

