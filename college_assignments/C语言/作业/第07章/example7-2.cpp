#include <stdio.h>

#define  NUM   10

int main()
{ 
  int  a[NUM],i,j,t;

  printf("input %d numbers: \n", NUM);
  for(i = 0; i < NUM; i++)  //输入NUM个整数
    scanf("%d", &a[i]);
  
  for(i = 1; i < NUM; i++)  //排序
    for(j = 0; j < NUM - i; j++)
      if (a[j] > a[j+1])
      {  
	    t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
 
  printf("the sorted numbers:\n");  //输出排好序的数据
  for(i = 0; i < NUM; i++)
    printf("%d ", a[i]);
  return 0;
}
