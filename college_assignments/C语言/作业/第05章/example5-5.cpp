#include <stdio.h>

int main()
{
  float a, b;    //����������ı���
  int tag = 0;   //����Ϸ��ı�־��0--�Ϸ���1--�Ƿ�
  char ch;       //���������
  float result;  //����������
  
  printf("input two number: ");  //��ʾ����������
  scanf("%f%f", &a, &b);         //����������
  fflush(stdin);                 //����̻�����
  printf("input arithmetic lable(+ - * /): ");   //��ʾ���������
  scanf("%c", &ch);              //���������
   
  switch(ch)  //�����������������ص�����
  {
    case '+':  result = a + b;   break;   //�ӷ�����
    case '-':  result = a - b;   break;   //��������
    case '*':  result = a * b;   break;   //�˷�����
    case '/':  if (!b)  //�������㣬�г����Ƿ�Ϊ0 
			   {
				 printf("divisor is zero!\n");  //��ʾ����Ϊ0 
				 tag = 1;  //������Ƿ���־
			   }
		       else  //������0
				 result = a / b;  //������
			   break;
    default:   printf("illegal arithmetic lable\n");  //�Ƿ��������
		       tag = 1;   //������Ƿ���־
  }
  
  if (!tag)  //����Ϸ�����ʾ������
	 printf("%.2f %c %.2f = %.2f\n", a, ch, b, result);
  return 0;
}	
