#include <stdio.h>

int take[5], n = 0;
int like[5][5] = { {0,0,1,1,0}, {1,1,0,0,1}, {0,1,1,0,1}, {0,0,0,1,0}, {0,1,0,0,1} };
int book[5] = {0,0,0,0,0};

void Try(int i);

int main()
{
  Try(0);
  return 0;
}

void Try(int i)
{
  int j, k;

  for(j = 0; j <=4; j++)     //j�������
  {
	if (like[i][j] > 0 && book[j] == 0)  //iϲ��j�飬��j��δ������
	{
	  take[i] = j;   //j��ָ�i
	  book[j] = 1;   //��¼j���ѷ�
	  if (i == 4)    //���i==4��������鷽��
	  {
		n++;         //��������1
		printf("===��%d������===\n", n);  //���������
		for(k = 0; k <=4; k++)      //������鷽��
			printf("%d����ָ�%c\n", take[k], 'A'+k);
		printf("\n");   //����
	  }
	  else             //���i!=4����������һ�˷���
		  Try(i+1);    //�ݹ����Try(i+1)
	  book[j] = 0;     //��¼j�����
	}   
  }
}