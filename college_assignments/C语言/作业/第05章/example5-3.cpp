#include <stdio.h>

int main()
{
  long   profit;             //���ӹ��̵�����
  int    grade;
  float  ratio;              //��ɱ���
  float  salary = 500;       //нˮ����ʼֵΪ����нˮ500 

  printf("Input profit: ");  //��ʾ�������ӹ��̵�����
  scanf("%ld", &profit);     //�������ӹ��̵�����

  //������ɱ���
  grade = (profit - 1) / 1000;	//������-1��������1000��ת����switch����е�case���
  switch(grade)
  { 
    case  0:  ratio = 0;            break;	// profit��1000 
    case  1:  ratio = (float)0.10;  break;	// 1000��profit��2000 
    case  2: 
    case  3: 
    case  4:  ratio = (float)0.15;  break;	// 2000��profit��5000 
    case  5: 
    case  6: 
    case  7: 
    case  8: 
    case  9:  ratio = (float)0.20;  break;	// 5000��profit��10000 */
    default:  ratio = (float)0.25;		    // 10000��profit 
  }

  salary += profit * ratio;           //���㵱��нˮ
  printf("salary = %.2f\n", salary);  //������
  return 0;
} 			
