#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu();//�˵�
int game();//��Ϸ
#define _CRT_SECURE_NO_WARNINGS
 
void menu()
{
	printf("***************************\n");
	printf("********** 1.play *********\n");
	printf("********** 0.exit *********\n");
	printf("***************************\n");
}
int game()         //return 0��   ��Ϸ���        return 1��   ��Ϸδ���
{
	int guess = 0;
	int aim = rand() % 100+1;     //����0��100
 	//printf("%d\n",aim);
	int cnt = 0;                 //����ѡ�����
	printf("��ʾ������8�λ�������֣�ÿ�βµ�������0��100����:>\n");
	system("pause");
	while (1)
	{
  	printf("������֣�\n");
  	scanf("%d", &guess);
  	if (guess > aim)
   	printf("�´���\n");
  	else if (guess == aim)
  	{
   printf("��ϲ�㣬�¶��ˣ�\n");
   return 0;
  }
  else
   printf("��С��\n");
  cnt++;
  if (cnt == 8)
  {
   printf("��Ϸ������ʧ�ܣ�:>\n");
   system("pause");
   system("cls");
   return 1;
  }
 }
}
#define _CRT_SECURE_NO_WARNINGS

//������
 
int main()
{
 int input = 0;
 srand((unsigned int)time(NULL));       //���������
 system("color f3");
 
 do
 {
  menu();
  printf("��ѡ��:>\n");
  scanf("%d", &input);
  switch (input)
  {
   case 1:
   input=game();
   break;
   case 0:
   printf("��Ϸ����\n");
   break;
   default:
   printf("ѡ�����������ѡ��\n");
   break;
  }
 
 } while (input);
 
 return 0;
}
