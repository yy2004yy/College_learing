#include <stdio.h>
#include <string.h>

#define CITYNUM  10
	
int main()
{   
  int i,j,k,num;
  char city[CITYNUM][20];
  char str[80];

  num = 0;  //ʵ������ĳ�������ʼ��Ϊ0
  for(i = 0; i < CITYNUM; i++)  //����������ַ���(���Ȳ��ܳ���19)
  {
	printf("input the name of the %dth city: ", i+1);
	gets(str);             //���������
	if (str[0] == 0)       //Ϊ�մ�����ʾ�������
	   break;
	if (strlen(str) > 19)  //�������ַ�������19ʱ������
	{
	  i--;
	  continue;
	}
	strcpy(city[i], str);  //������ĳ��������浽�ַ���������
	num++;                 //ʵ������ĳ�������1
  }

  for(i = 0; i < num - 1; i++)
  {
    k = i;  //kΪ��ǰ��������С���ַ���������±꣬��ʼ����Ϊi
    for(j = i+1; j < num; j++) //���ұ�city[k]С���ַ������±����k��
      if (stricmp(city[k], city[j]) > 0) 
         k = j;
	
    if (k != i)   //����С���������ַ���city[k]��city[i]����
    {
	  strcpy(str, city[i]);
	  strcpy(city[i], city[k]);
	  strcpy(city[k], str);
    }
  }

  for(i = 0; i < num; i++)  //��ʾ�����Ľ��
  printf("%s  ", city[i]);
  printf("\n");
  return 0;
}
