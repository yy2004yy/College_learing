#include <stdio.h>

void compare(int a, int b);  //Ҳ����д��void compare(int,int);

int main()
{   
  int i = 2;

  compare(i, i++);           //��������
  printf("i = %d\n",i);
  return 0;
}

void compare(int a, int b)  //��������,���β��޷���ֵ
{   
  printf("a = %d  b = %d\n",a,b);
  if ( a > b)  
	 printf("a > b\n");
  else 
	if (a == b)  
	   printf("a = b\n");
    else 
	   printf("a < b\n");
}
