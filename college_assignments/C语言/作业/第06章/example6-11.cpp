#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, j, k, m, n, size;

  printf("input size: ");  //�����С��ʾ
  scanf("%d", &size);      //�����С
  if (size <= 0 || size % 2 == 0)  //���ΪС�ڻ����0������Ϊż��
  {
	 printf("the size is error!\n");  //��ʾ��С����
	 exit(-1);                        //�������
  }
  
  for (i = 1; i <= size; i++)  //��������
  {
	n = (i <= (size+1)/2) ? i : size-i+1;   //ÿ����"*"�ŵĸ���
	n = 2 * n - 1;
	m = (size - n) / 2 + 15;  //ÿ�д�ӡ"*"֮ǰӦ��ӡ�Ŀո���
	for (k = 1; k <= m; k++)  //��ӡÿ��ǰ��Ŀո�
		printf(" ");
    for (j = 1; j <= n; j++)  //��ӡÿ�е�"*"
	    printf("*");
	printf("\n");            //��ӡһ�к󣬻س�����
  }
  return 0;
}
