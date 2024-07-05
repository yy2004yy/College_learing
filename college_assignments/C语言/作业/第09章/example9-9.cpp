#include <stdio.h>
#include <string.h>
	
int main()
{   
  int i,j,k;
  char *pcity[] = {"Wuhan","Beijing","Shanghai","Tianjin","Guangzhou",""};
  char *ptemp;

  for(i = 0; strcmp(pcity[i],"") != 0; i++)
  {
    k = i;  //k为当前最小字符串的字符指针数组的下标，初始假设为i
    for(j = i+1; strcmp(pcity[j],"") != 0; j++) //查找比pcity[k]小的字符串的下标放入k中
      if (strcmp(pcity[k], pcity[j]) > 0) 
         k = j;
	
    if (k != i)   //将最小字符串的地址pcity[k]与pcity[i]交换
    {
      ptemp = pcity[i];
      pcity[i] = pcity[k];
      pcity[k] = ptemp;
    }
  }

  for(i = 0; strcmp(pcity[i],"") != 0; i++)  //显示排序后的结果
  printf("%s  ", pcity[i]);
  printf("\n");
  return 0;
}
