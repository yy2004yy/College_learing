#include <stdio.h>
#define  NUM   10

int main( )
{
  int a[NUM], i, j, k, t;

  printf ("input %d numbers: \n", NUM);
  for (i = 0; i < NUM; i++)       //����NUM������
     scanf ("%d", &a[i]);

  for (i = 0; i < NUM - 1; i++)  //ѡ����������
  {
    k = i;        //kΪ��ǰ��С�����±꣬��ʼֵ��Ϊi
    for (j = i+1; j < NUM; j++)   //���ұ�a[k]С�������±����k��
      if (a[k] > a[j])  //���ڱ�a[k]С����a[j]
        k = j;       //������С�����±�ֵ
    if (k != i)   //�����С�����±��и��ģ�����С��a[k]��a[i]����
    {
      t = a[i];
      a[i] = a[k];
      a[k] = t;
    }
  }

  printf ("the sorted numbers:\n");  //����ź��������
  for (i = 0; i < NUM; i++)
    printf ("%d ", a[i]);
  return 0;
}
