#include <stdio.h>

#define  NUM   10

int main()
{ 
  int  a[NUM],i,j,t;

  printf("input %d numbers: \n", NUM);
  for(i = 0; i < NUM; i++)  //����NUM������
    scanf("%d", &a[i]);
  
  for(i = 1; i < NUM; i++)  //����
    for(j = 0; j < NUM - i; j++)
      if (a[j] > a[j+1])
      {  
	    t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
 
  printf("the sorted numbers:\n");  //����ź��������
  for(i = 0; i < NUM; i++)
    printf("%d ", a[i]);
  return 0;
}
