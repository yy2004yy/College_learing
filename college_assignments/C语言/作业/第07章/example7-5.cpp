#include <stdio.h>

#define NUM 100

int main()
{
  int   i, stu_num;
  float score[NUM];               //���ѧ���ɼ�����
  float maxscore, minscore,       //��߷֡���ͷ�
  float avescore, passratio;      //ƽ���֡�������
  int   great60,  greatavescore;  //��������������ƽ��������

  while (1)  //����ʵ��ѧ������
  {
	printf("input the number of student(<=%d): ",NUM);
	scanf("%d",&stu_num);
	if (stu_num >= 1 && stu_num <= NUM)
	   break;
	printf("wrong input! try again!\n");
  }

  avescore = 0;
  for (i = 0; i < stu_num; i++)  //����ÿ��ѧ���ĳɼ�
  {
	printf("input the score of the %dth student: ", i+1);
	scanf("%f", &score[i]);
	avescore += score[i];   //ͳ���ܷ�
  }

  avescore /= stu_num;      //����ƽ����

  //������߷֡���ͷ֡���������������ƽ��������
  maxscore = 0;        
  minscore = 100;
  great60  = 0;
  greatavescore = 0;
  for (i = 0; i < stu_num; i++)
  {
	maxscore = score[i] > maxscore ? score[i] : maxscore;
	minscore = score[i] < minscore ? score[i] : minscore;
	if (score[i] >= 60)        //��������60������������1
	   great60++;
	if (score[i] >= avescore)  //��������ƽ���֣�����ƽ����������1
	   greatavescore++;
  }

  passratio = 1.0 *great60 / stu_num;  //���㼰����

  printf("======total result======\n");  //��ʾͳ�ƽ��
  printf("the highest score is %.2f\n", maxscore);
  printf("the lowest  score is %.2f\n", minscore);
  printf("the average score is %.2f\n", avescore);
  printf("the pass ratio is %.2f%%\n", passratio*100);
  printf("the number of pass is %d\n",great60);
  printf("the number of exceed average score is %d\n",greatavescore);
  return 0;
}
