#include <stdio.h>
#include <string.h>

#define CITYNUM  10
	
int main()
{   
  int i,j,k,num;
  char city[CITYNUM][20];
  char str[80];

  num = 0;  //实际输入的城市数初始化为0
  for(i = 0; i < CITYNUM; i++)  //输入城市名字符串(长度不能超过19)
  {
	printf("input the name of the %dth city: ", i+1);
	gets(str);             //输入城市名
	if (str[0] == 0)       //为空串，表示输入结束
	   break;
	if (strlen(str) > 19)  //城市名字符串超过19时，重输
	{
	  i--;
	  continue;
	}
	strcpy(city[i], str);  //将输入的城市名保存到字符串数组中
	num++;                 //实际输入的城市数增1
  }

  for(i = 0; i < num - 1; i++)
  {
    k = i;  //k为当前城市名最小的字符串数组的下标，初始假设为i
    for(j = i+1; j < num; j++) //查找比city[k]小的字符串的下标放入k中
      if (stricmp(city[k], city[j]) > 0) 
         k = j;
	
    if (k != i)   //将最小城市名的字符串city[k]与city[i]交换
    {
	  strcpy(str, city[i]);
	  strcpy(city[i], city[k]);
	  strcpy(city[k], str);
    }
  }

  for(i = 0; i < num; i++)  //显示排序后的结果
  printf("%s  ", city[i]);
  printf("\n");
  return 0;
}
