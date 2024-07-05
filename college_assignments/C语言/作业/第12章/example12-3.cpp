#include <stdio.h>
#include <stdlib.h>

void main()
{ 
  FILE *fp1,*fp2;
  char str[] = "123456789";

  fp1 = fopen("wang.txt","w");  //创建文本文件wang.txt   	
  if (fp1 == NULL)              //创建文件失败
  {  
    printf("can not open file: wang.txt\n");
    exit(0);
  }
  
  fputs(str,fp1);               //将字符串"12345678"写入文件
  fputs("\nabcd",fp1);      //写入第一行文本的换行符和下一行文本
  fclose(fp1); 	                //关闭文件
  
  fp2 = fopen("wang.txt","rt"); //以只读方式打开wang.txt文件
  fgets(str,8,fp2);             //读取字符串，最大长度是7，将是"1234567"
  printf("%s\n",str);
  fgets(str,8,fp2);             //读取字符串，最大长度是7，实际上将是"89\n"
  printf("%s\n",str);
  fgets(str,8,fp2);             //读取字符串，最大长度是7，实际上将是"abcd"
  printf("%s\n",str);
  
  fclose(fp2);                  //关闭打开的文件
  
}
		