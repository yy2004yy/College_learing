#include <stdio.h>

struct Stu_Tea
{
  char  name[10];  //姓名
  int   age;       //年龄
  char  job;       //工作s--表示学生，t--表示教师
  union
  { 
    int  classno;      //学生班级号
    char office[10];   //教师教研室名
  } depart;
};
	
int main ( )
{
  struct Stu_Tea body[2];
  int  i;
 
  for (i = 0; i < 2; i++)  //输入学生或教师信息
  {
    printf ("input name,age,job and department\n");
    scanf ("%s %d %c", body[i].name, &body[i].age, &body[i].job);
    if (body[i].job == 's')   //是学生,输入班级号
       scanf ("%d", &body[i].depart.classno);
    else                 //是教师，输入教研室名
       scanf ("%s", body[i].depart.office);
  }
	
  printf ("name\tage job class/office\n");  //显示输入的学生、教师信息
  for (i = 0; i < 2; i++)
  {
    if (body[i].job == 's')
       printf ("%s\t%3d%3c%d\n", body[i].name, body[i].age, body[i].job, body[i].depart.classno);
    else
       printf ("%s\t%3d %3c %s\n", body[i].name, body[i].age, body[i].job, body[i].depart.office);
  }
  return 0;
}
