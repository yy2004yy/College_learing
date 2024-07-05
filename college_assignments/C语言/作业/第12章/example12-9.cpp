#include <stdio.h>
#include <stdlib.h>

void main(int argc,char *argv[])
{
  FILE *fp;
  long length;

  if (argc != 2)  //�����в�������
  {
	printf("Useage: ִ���ļ���  filename\n");
	exit(0);
  }

  fp = fopen(argv[1],"rb");   //�Զ��ķ�ʽ���ļ�
  if(fp == NULL)   //���ļ�ʧ��
  {
    printf("file not found!\n");
    exit(0);
  }
  fseek(fp,0L,SEEK_END);   //�ļ�λ��ָ��ָ���ļ�β
  length = ftell(fp);      //ȡ�ļ�λ��ָ�뵱ǰ��λ�ã����ļ��ĳ���
  printf("Length of File is %ld bytes\n",length);  //��ʾ�ļ�����

  fclose(fp);   //�ر��ļ�
}
