#include <stdio.h>
#include <string.h>

struct person
{   
  char name[20];   //��ѡ������
  int  count;      //��Ʊ��
} leader[3]={"Li",0,"Zhang",0,"Wang",0}; 

int main()
{    
  int  i,j;  
  char leader_name[20];

  while(1)    //ͳ�ƺ�ѡ�˵�Ʊ��
  {   
    scanf("%s",leader_name);  //�����ѡ������
	if (strcmp(leader_name,"0") == 0)  //����Ϊ"0"����
	   break;
    for(j = 0; j < 3; j++)   //�Ƚ��Ƿ�Ϊ�Ϸ���ѡ��
	   if (strcmp(leader_name,leader[j].name) == 0)  //�Ϸ�
	      leader[j].count++;   //��Ʊ����1
  }

  for(i = 0; i < 3; i++)  //��ʾ��ѡ�˵�Ʊ��
     printf("%5s : %d\n",leader[i].name,leader[i].count);
  return 0;
}
