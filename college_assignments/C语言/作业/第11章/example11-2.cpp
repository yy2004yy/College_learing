#include <stdio.h>
#include <string.h>

struct person
{   
  char name[20];   //候选人姓名
  int  count;      //得票数
} leader[3]={"Li",0,"Zhang",0,"Wang",0}; 

int main()
{    
  int  i,j;  
  char leader_name[20];

  while(1)    //统计候选人得票数
  {   
    scanf("%s",leader_name);  //输入候选人姓名
	if (strcmp(leader_name,"0") == 0)  //输入为"0"结束
	   break;
    for(j = 0; j < 3; j++)   //比较是否为合法候选人
	   if (strcmp(leader_name,leader[j].name) == 0)  //合法
	      leader[j].count++;   //得票数加1
  }

  for(i = 0; i < 3; i++)  //显示后选人得票数
     printf("%5s : %d\n",leader[i].name,leader[i].count);
  return 0;
}
