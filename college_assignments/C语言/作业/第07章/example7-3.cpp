#include <stdio.h>

#define  NUM   10

int main()
{ 
  int  a[NUM],i,j,t;
  int  flag;

  printf("input %d numbers: \n", NUM);
  for(i = 0; i < NUM; i++)  //����NUM������
    scanf("%d", &a[i]);
  
  for(i = 1; i < NUM; i++)        //�ִΣ���NUM-1��
  {
	flag = 0;
    for(j = 0; j < NUM - i; j++)  //һ��ð�ݲ���
      if (a[j] > a[j+1])          //����a[j]��a[j+1]
      {  
	    t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
		flag = 1;
      }
	if (flag == 0) break;
  }
 
  printf("the sorted numbers:\n");  //����ź��������
  for(i = 0; i < NUM; i++)
    printf("%d ", a[i]);
  return 0;
}
