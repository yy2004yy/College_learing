/* This is the third C program */
#include  <stdio.h>   //Ԥ��������

int max(int a, int b);  //�Զ��庯������

int main( )  //�޲������޷���ֵ��������
{
  int x, y, z;  //�����������ͱ���x,y,z
	
  scanf("%d%d", &x, &y);  //ͨ�����̶Ա���x,y��ֵ
  z = max(x, y);          //�����Զ��庯��max��x,y�����ֵ�����������z
  printf("max = %d\n", z);  //�⺯������
  return 0;
}

//�û��Զ��庯��,���������е����ֵ
int max(int a, int b)  //���������βΣ��з���ֵ
{
  int c;    //����һ�����ͱ���

  if (a > b)  //���a����b
c = a;   //��a��ֵ����c
  else        //����(aС�ڻ����b)
     c = b;   //��b��ֵ����c
  return(c);  //��c��ֵ����
}
