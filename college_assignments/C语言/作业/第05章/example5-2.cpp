#include <stdio.h>
	
int main()
{
  long   profit;        //���ӹ��̵�����
  float  ratio;         //��ɱ���
  float  salary = 500;  //нˮ����ʼֵΪ����нˮ500  
     
  printf("Input profit: ");  //��ʾ�������ӹ��̵�����
  scanf("%ld", &profit);     //�������ӹ��̵�����
  
  //������ɱ���
  if (profit <= 1000)
	 ratio = 0;
  else if (profit <= 2000)
	      ratio = (float)0.10;
  else if (profit <= 5000)
	      ratio = (float)0.15;
  else if (profit <= 10000)
	      ratio = (float)0.20;
  else ratio = (float)0.25;

  salary += profit * ratio;           //���㵱��нˮ
  printf("salary = %.2f\n", salary);  //������
  return 0;
}