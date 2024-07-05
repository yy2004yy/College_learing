/**
 * @file exp4Exmpl1.h 
 * @brief: 综合实验4例1_交换结构体成员(项目)的头文件
 **/
//库函数头文件
#include <stdio.h>
#include <string.h>

//宏常量、全局变量等
#define N 3

//结构体、链表等复杂数据类型的定义
struct Person{
  char name[20];
  int points; 
};

//自定义函数的声明
void swap(int *p1, int *p2);
