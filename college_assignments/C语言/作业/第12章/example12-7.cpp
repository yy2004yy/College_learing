#include <stdio.h>
#include <stdlib.h>

void main()
{
  int i = 3;
  float f = (float)9.8;
  FILE *fp;

  fp = fopen("wang.txt","w");   //创建文本文件wang.txt
  if (fp == NULL)               //创建失败
  {
	printf("can't create file: wang.dat\n");
	exit(0);
  }
  fprintf(fp,"%2d,%6.2f",i,f);  //将变量i和f的值格式化输出到文件中
  fclose(fp);  //关闭文件

  fp = fopen("wang.txt","r");   //以读的方式打开文件wang.txt
  if (fp == NULL)               //打开失败
  {
	printf("can't open file: wang.dat\n");
	exit(0);
  }
  i = 0;      //i清0
  f = 0;      //f清0
  fscanf(fp,"%d,%f",&i,&f);    //从文件中读取数值到变量i和f
  fclose(fp);                  //关闭文件

  printf("i = %2d, f = %6.2f\n",i,f);  //显示从文件中读取的变量i和f的值
  
}