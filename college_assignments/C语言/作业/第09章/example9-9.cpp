#include <stdio.h>
#include <string.h>
	
int main()
{   
  int i,j,k;
  char *pcity[] = {"Wuhan","Beijing","Shanghai","Tianjin","Guangzhou",""};
  char *ptemp;

  for(i = 0; strcmp(pcity[i],"") != 0; i++)
  {
    k = i;  //kΪ��ǰ��С�ַ������ַ�ָ��������±꣬��ʼ����Ϊi
    for(j = i+1; strcmp(pcity[j],"") != 0; j++) //���ұ�pcity[k]С���ַ������±����k��
      if (strcmp(pcity[k], pcity[j]) > 0) 
         k = j;
	
    if (k != i)   //����С�ַ����ĵ�ַpcity[k]��pcity[i]����
    {
      ptemp = pcity[i];
      pcity[i] = pcity[k];
      pcity[k] = ptemp;
    }
  }

  for(i = 0; strcmp(pcity[i],"") != 0; i++)  //��ʾ�����Ľ��
  printf("%s  ", pcity[i]);
  printf("\n");
  return 0;
}
