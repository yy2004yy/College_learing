#include <stdio.h>

int main()
{
  long   profit;             //所接工程的利润
  int    grade;
  float  ratio;              //提成比率
  float  salary = 500;       //薪水，初始值为保底薪水500 

  printf("Input profit: ");  //提示输入所接工程的利润
  scanf("%ld", &profit);     //输入所接工程的利润

  //计算提成比率
  grade = (profit - 1) / 1000;	//将利润-1、再整除1000，转化成switch语句中的case标号
  switch(grade)
  { 
    case  0:  ratio = 0;            break;	// profit≤1000 
    case  1:  ratio = (float)0.10;  break;	// 1000＜profit≤2000 
    case  2: 
    case  3: 
    case  4:  ratio = (float)0.15;  break;	// 2000＜profit≤5000 
    case  5: 
    case  6: 
    case  7: 
    case  8: 
    case  9:  ratio = (float)0.20;  break;	// 5000＜profit≤10000 */
    default:  ratio = (float)0.25;		    // 10000＜profit 
  }

  salary += profit * ratio;           //计算当月薪水
  printf("salary = %.2f\n", salary);  //输出结果
  return 0;
} 			
