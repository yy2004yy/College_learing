#include <stdio.h>

#define NUM_std     5    //������ų���ѧ������Ϊ5
#define NUM_course  4    //������ų����γ�����Ϊ4

int main()
{ 
  int i,j;

  float score[NUM_std+1][NUM_course+1] = {0};  //����ɼ����飬������Ԫ�س�ʼ��Ϊ0

  for(i = 0; i < NUM_std; i++)  
    for(j = 0; j < NUM_course; j++)
	{
	  printf("input the mark of %dth courseof %dth student: ", j+1, i+1);
	  scanf("%f", &score[i][j]);  //�����i��ѧ���ĵ�j�ſεĳɼ�
	}
  
  for(i = 0; i < NUM_std; i++)
  {
    for(j = 0; j < NUM_course; j++)
	{ 
	  score[i][NUM_course] += score[i][j];  //���i��ѧ�����ܳɼ�
	  score[NUM_std][j] += score[i][j];	    //���j�ſε��ܳɼ�
	}
	score[i][NUM_course] /= NUM_course;     //���i���˵�ƽ���ɼ�
  }
  for(j = 0; j < NUM_course; j++)
     score[NUM_std][j] /= NUM_std;	        //���j�ſε�ƽ���ɼ�
  
  printf(" NO.       C1      C2      C3      C4     AVER\n"); //�����ͷ
  for(i = 0; i < NUM_std; i++)  //���ÿ��ѧ���ĸ��Ƴɼ���ƽ���ɼ�
  { 
	printf("STU%d\t",i+1);
    for(j = 0; j < NUM_course+1; j++)
       printf("%6.1f\t",score[i][j]);
    printf("\n");
  }
    
  printf("---------------------------------------");  //���1���̻���
  printf("\nAVER_C  ");
  for(j = 0;j < NUM_course; j++)  //���ÿ�ſγ̵�ƽ���ɼ�
     printf("%6.1f\t",score[NUM_std][j]);
  printf("\n");
  return 0;
 }			