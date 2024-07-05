#include <stdio.h>

#define  NUM   10

int main()
{ 
  int  a[NUM],i,j,t;
  int  flag;

  printf("input %d numbers: \n", NUM);
  for(i = 0; i < NUM; i++)  //输入NUM个整数
    scanf("%d", &a[i]);
  
  for(i = 1; i < NUM; i++)        //轮次，共NUM-1次
  {
	flag = 0;
    for(j = 0; j < NUM - i; j++)  //一次冒泡操作
      if (a[j] > a[j+1])          //交换a[j]和a[j+1]
      {  
	    t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
		flag = 1;
      }
	if (flag == 0) break;
  }
 
  printf("the sorted numbers:\n");  //输出排好序的数据
  for(i = 0; i < NUM; i++)
    printf("%d ", a[i]);
  return 0;
}
