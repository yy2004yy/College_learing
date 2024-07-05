#include <stdio.h>
#include <stdlib.h>

struct Grade_Info
{
  int score;    
  struct Grade_Info *next;
};
typedef struct Grade_Info NODE; 

NODE *Create_LinkList();
void Insert_LinkList(NODE *head,NODE *pnew,int i);
void Delete_LinkList(NODE *head,int i);  
void Display_LinkList(NODE *head);
void Free_LinkList(NODE *head);  

int main()
{
  NODE *head,*pnew;

  head = Create_LinkList();  //创建链表
  if (head == NULL)          //创建失败
	 return -1;

  printf("after create: ");
  Display_LinkList(head);    //输出链表中的值

  pnew = (NODE *)malloc(sizeof(NODE));  //新建一插入的节点
  if (pnew == NULL)  //创建失败,则返回
  {
    printf("no enough memory!\n");
    return -1;
  }  
  pnew->score = 88;    
  Insert_LinkList(head,pnew,3);  //将新节点插入节点3的后面
  printf("after insert: ");
  Display_LinkList(head);        //输出链表中的值

  Delete_LinkList(head,3);       //删除链表中节点3
  printf("after delete: ");
  Display_LinkList(head);        //输出链表中的值

  Free_LinkList(head);           //销毁链表
  return 0;
}

//创建链表
NODE *Create_LinkList() 
{
  NODE *head, *tail, *pnew;
  int score;

  head = (NODE *)malloc(sizeof(NODE));  //创建头节点
  if (head == NULL)                     //创建失败,则返回
  {
    printf("no enough memory!\n");
    return(NULL);
  }  
  head->next = NULL;       //头节点的指针域置NULL
  tail = head;             //开始时尾指针指向头节点

  printf("input the score of students:\n");
  while(1)                 //创建学生成绩线性链表
  {
    scanf("%d",&score);    //输入成绩
    if (score < 0)         //成绩为负,循环退出
       break;
    pnew =  (NODE *)malloc(sizeof(NODE));  //创建一新节点
    if (pnew == NULL)      //创建新节点失败,则返回
	{
      printf("no enough memory!\n");
      return(NULL);
	}  
	pnew->score = score;   //新节点数据域放输入的成绩
    pnew->next = NULL;     //新节点指针域置NULL

    tail->next = pnew;     //新节点插入到链表尾
    tail = pnew;           //味指针指向当前的尾节点
  }
  return(head);            //返回创建的链表的头指针
}

//在链表的第i个节点后插入一新节点
void Insert_LinkList(NODE *head,NODE *pnew,int i)  
{
  NODE *p;
  int j;

  p = head;
  for(j = 0; j < i && p != NULL; j++)  //将p指向要插入的第i个节点
     p = p->next;
  if (p == NULL)  //表明链表中第i个节点不存在
  {
	printf("the %d node not foundt!\n",i);
	return;
  }

  pnew->next = p->next ;  //将插入节点的指针域指向第i个节点的后继节点
  p->next = pnew;         //将第i个节点的指针域指向插入节点
}  

//删除链表中的第i个节点
void Delete_LinkList(NODE *head,int i)  
{
  NODE *p,*q;
  int j;

  if (i == 0)
	return;

  p = head;
  for(j = 1; j < i && p->next != NULL; j++)  //将p指向要删除的第i个节点的前驱节点
     p = p->next;
  if (p->next == NULL)  //表明链表中第i个节点不存在
  {
	printf("the %d node not foundt!\n",i);
	return;
  }
  q = p->next;        //q指向待删除的节点i
  p->next = q->next ; //删除节点i
  free(q);
}  


//显示链表中的数据域的值
void Display_LinkList(NODE *head)  
{
  NODE *p;

  for(p = head->next; p != NULL; p = p->next)
	 printf("%d ",p->score);
  printf("\n");
}


//销毁链表
void Free_LinkList(NODE *head)  
{
  NODE *p,*q;
  
  p = head;
  while(p->next != NULL)
  {
    q = p->next;
	p->next = q->next;
	free(q);
  }
  free(head);
}
