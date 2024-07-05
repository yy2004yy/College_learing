#include "EXP4_structMultifile.h"  //项目的其它.c文件中都包含上这个头文件

/*
  自定义函数的定义可以写在多个.c文件中
  只需要都添加到项目文件列表里，并在头文件中做好声明即可
*/
void swap(int *p1, int *p2) {
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
