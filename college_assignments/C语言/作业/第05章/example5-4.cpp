#include <stdio.h>

int main()
{
  int year, leap = 0;	  // leap=0��Ԥ��Ϊ������

  printf("Please input the year: ");  //��ʾ�������
  scanf("%d", &year);     //�������
  
  if (year % 4 == 0)      //�����4����  
     if (year % 100 != 0) //�������100����
		leap = 1;         //��Ϊ����
  if (year % 400 == 0)    //�����400����
   	 leap = 1;            //��Ϊ����
  
  //������
  if (leap) //���������(leap==1)  
	 printf("%d is a leap year.\n", year);
  else   
	 printf("%d is not a leap year.\n", year);
  return 0;
}	
