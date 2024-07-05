#include <stdio.h>

#define NUM 100

int main()
{
  int   i, stu_num;
  float score[NUM];               //存放学生成绩数组
  float maxscore, minscore,       //最高分、最低分
  float avescore, passratio;      //平均分、及格率
  int   great60,  greatavescore;  //及格人数、超过平均分人数

  while (1)  //输入实际学生人数
  {
	printf("input the number of student(<=%d): ",NUM);
	scanf("%d",&stu_num);
	if (stu_num >= 1 && stu_num <= NUM)
	   break;
	printf("wrong input! try again!\n");
  }

  avescore = 0;
  for (i = 0; i < stu_num; i++)  //输入每个学生的成绩
  {
	printf("input the score of the %dth student: ", i+1);
	scanf("%f", &score[i]);
	avescore += score[i];   //统计总分
  }

  avescore /= stu_num;      //计算平均分

  //计算最高分、最低分、及格人数、超过平均分人数
  maxscore = 0;        
  minscore = 100;
  great60  = 0;
  greatavescore = 0;
  for (i = 0; i < stu_num; i++)
  {
	maxscore = score[i] > maxscore ? score[i] : maxscore;
	minscore = score[i] < minscore ? score[i] : minscore;
	if (score[i] >= 60)        //分数超过60，及格人数增1
	   great60++;
	if (score[i] >= avescore)  //分数超过平均分，超过平均分人数增1
	   greatavescore++;
  }

  passratio = 1.0 *great60 / stu_num;  //计算及格率

  printf("======total result======\n");  //显示统计结果
  printf("the highest score is %.2f\n", maxscore);
  printf("the lowest  score is %.2f\n", minscore);
  printf("the average score is %.2f\n", avescore);
  printf("the pass ratio is %.2f%%\n", passratio*100);
  printf("the number of pass is %d\n",great60);
  printf("the number of exceed average score is %d\n",greatavescore);
  return 0;
}
