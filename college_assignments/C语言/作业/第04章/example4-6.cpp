#include  <stdio.h>
	
int main()
{
  unsigned long no;               //ѧ��
  unsigned int year, month, day;  //���գ��ꡢ�¡��գ�
  unsigned char sex;              //�Ա�
  float chinese, math, english;   //���ġ���ѧ��Ӣ��ɼ�
  float total, average;           //�ܷ֡�ƽ����
	
  printf("input the student's NO: ");
  scanf("%8ld", &no);
  printf("input the student's Birthday(yyyy-mm-dd): ");
  scanf("%4d-%2d-%2d", &year, &month, &day);
  fflush(stdin);                 //������̻�����
  printf("input the student's Sex(M/F): ");
  scanf("%c", &sex);
  printf("input the student's Scores(chinese, math, english): ");
  scanf("%f,%f,%f", &chinese, &math, &english);
  total = chinese + math + english;   //�����ܷ�
  average = total / 3;                //����ƽ����

  printf("\n===NO=======birthday==sex==chinese==math==english==total==average\n");
  printf("%08ld   %4d-%02d-%02d  %c     %-5.1f  %-5.1f  %-5.1f   %-5.1f   %-5.1f\n", 
	      no, year, month, day, sex, chinese, math, english, total, average);
  return 0;
}
