#include <stdio.h>
#include <stdlib.h>

enum SEX {man,female};

struct Student_Info
{
  char          no[9];      //学号
  char          name[20];   //姓名
  enum SEX      sex;        //性别
  unsigned int  age;        //年龄
  unsigned int  classno;    //班级
  float         grade;      //成绩
};

typedef struct Student_Info STUDENT;

STUDENT *GetStuInfo(int i);
void SortStuInfo(STUDENT **pstu, int num);
void FreeMemory(STUDENT **pstu, int num);

int main()
{
  STUDENT **pstu;
  int i, num;
  
  printf("input the number of the students: ");
  scanf("%d", &num);
  if (num <= 0)
     return -1;
  pstu = (STUDENT **)malloc(num * sizeof(STUDENT *));
  if (pstu == NULL)
  {
	printf("not enough memory!\n");
	return -1;
  }
  
  //建立每个学生信息的记录
  for (i = 0; i < num; i++)
  {
    pstu[i] = GetStuInfo(i);
	if (pstu[i] == NULL)
	{
	  printf("not enough memory!\n");
	  FreeMemory(pstu, i);
	  return -1;
	}
  }

  SortStuInfo(pstu,num);  //对学生信息按分数从高到低排序
  
  printf("\n===============sort result==================\n");
  for (i = 0; i < num; i++)  //显示排序后的结果
  {
	printf("%12s%20s%9s%5d%5d%8.1f",pstu[i]->no,pstu[i]->name,
		(pstu[i]->sex == man)? "man" : "female",pstu[i]->age,pstu[i]->classno,pstu[i]->grade);
	printf("\n");
  }

  FreeMemory(pstu, num);  //释放动态分配的内存
  return 0;
}

//输入学生信息
STUDENT *GetStuInfo(int i)
{
  STUDENT *p;
  char sex;

  p = (STUDENT *)malloc(sizeof(STUDENT));
  if (p == NULL)
	 return NULL;

  printf("\n====input %dth student's information==== \n",i+1);
  printf("no: ");
  scanf("%s",p->no);
  printf("name: ");
  scanf("%s",p->name);
  fflush(stdin);
  while(1)
  {
    printf("sex(M,F): ");
    scanf("%c",&sex);
    if (sex == 'M' || sex == 'F')
	   break;
	fflush(stdin);
  }
  p->sex = (sex == 'M') ? man : female;
  printf("age: ");
  scanf("%d",&p->age);
  printf("classno: ");
  scanf("%d",&p->classno);
  printf("grade: ");
  scanf("%f",&p->grade);
  return(p);
}

//对学生信息按分数从高到低排序
void SortStuInfo(STUDENT **pstu, int num)
{
  STUDENT *p;
  int i,j,k;

  for(i = 0; i < num-1; i++)
  {
    k = i;
	for(j = i+1; j < num; j++)
	   if (pstu[j]->grade > pstu[k]->grade)
           k = j;
	if ( k != i)
	{
	  p = pstu[i];
	  pstu[i] = pstu[k];
	  pstu[k] = p;
	}
  }
}

//释放动态分配的内存
void FreeMemory(STUDENT **pstu, int num)
{
  int i;

  for (i = 0; i < num; i++)
    free(pstu[i]);
  free(pstu);
}
