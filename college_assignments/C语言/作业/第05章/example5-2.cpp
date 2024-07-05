#include <stdio.h>
	
int main()
{
  long   profit;        //所接工程的利润
  float  ratio;         //提成比率
  float  salary = 500;  //薪水，初始值为保底薪水500  
     
  printf("Input profit: ");  //提示输入所接工程的利润
  scanf("%ld", &profit);     //输入所接工程的利润
  
  //计算提成比率
  if (profit <= 1000)
	 ratio = 0;
  else if (profit <= 2000)
	      ratio = (float)0.10;
  else if (profit <= 5000)
	      ratio = (float)0.15;
  else if (profit <= 10000)
	      ratio = (float)0.20;
  else ratio = (float)0.25;

  salary += profit * ratio;           //计算当月薪水
  printf("salary = %.2f\n", salary);  //输出结果
  return 0;
}