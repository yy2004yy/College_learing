#include <stdio.h>

#define MAX 15

int main()
{
  int m,mm,i,j,k,ni,nj;
  int magic[MAX][MAX] = {0};

  printf("Enter the number you wanted: ");
  scanf("%d", &m);

  if ((m <= 0) || (m % 2 == 0))
  {
    printf("Error in input data.\n");
	return -1;
  }
  
  mm = m * m;
  i = 0;  //��һ��ֵ��λ��
  j = m / 2;
  for(k = 1; k <= mm; k++)
  {
    magic[i][j] = k;
    //�����Ϸ����������
    if (i == 0)  //����һ��
       ni = m - 1;  //��һ��λ��������һ��
    else
       ni = i - 1;
	if (j == m - 1)  //���Ҷ�
	   nj = 0;  //��һ��λ���������
	else
	   nj = j + 1;
	//�ж����Ϸ������Ƿ�������
	if (magic[ni][nj] == 0)  //���Ϸ���ֵ
	{
	  i = ni;
	  j = nj;
	}
	else  //���Ϸ�������������
      i++;
  }

  for (i = 0; i < m; i++)  //��ʾ���Ľ�� 
  {
    for (j = 0; j < m; j++)
      printf("%4d", magic[i][j]);
	printf("\n");
  }
  return 0;
}