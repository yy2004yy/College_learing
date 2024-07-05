#include <stdio.h>

#define NUM_std     5    //定义符号常量学生人数为5
#define NUM_course  4    //定义符号常量课程门数为4

int main()
{ 
  int i,j;

  float score[NUM_std+1][NUM_course+1] = {0};  //定义成绩数组，并将各元素初始化为0

  for(i = 0; i < NUM_std; i++)  
    for(j = 0; j < NUM_course; j++)
	{
	  printf("input the mark of %dth courseof %dth student: ", j+1, i+1);
	  scanf("%f", &score[i][j]);  //输入第i个学生的第j门课的成绩
	}
  
  for(i = 0; i < NUM_std; i++)
  {
    for(j = 0; j < NUM_course; j++)
	{ 
	  score[i][NUM_course] += score[i][j];  //求第i个学生的总成绩
	  score[NUM_std][j] += score[i][j];	    //求第j门课的总成绩
	}
	score[i][NUM_course] /= NUM_course;     //求第i个人的平均成绩
  }
  for(j = 0; j < NUM_course; j++)
     score[NUM_std][j] /= NUM_std;	        //求第j门课的平均成绩
  
  printf(" NO.       C1      C2      C3      C4     AVER\n"); //输出表头
  for(i = 0; i < NUM_std; i++)  //输出每个学生的各科成绩和平均成绩
  { 
	printf("STU%d\t",i+1);
    for(j = 0; j < NUM_course+1; j++)
       printf("%6.1f\t",score[i][j]);
    printf("\n");
  }
    
  printf("---------------------------------------");  //输出1条短划线
  printf("\nAVER_C  ");
  for(j = 0;j < NUM_course; j++)  //输出每门课程的平均成绩
     printf("%6.1f\t",score[NUM_std][j]);
  printf("\n");
  return 0;
 }			