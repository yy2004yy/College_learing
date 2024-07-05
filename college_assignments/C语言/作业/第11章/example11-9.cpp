#include <stdio.h>
#include <malloc.h>

struct LNode
{
  int data;
  struct LNode *next;
};
typedef struct LNode NODE;

NODE *Create_LinkList_Order();
void Delete_LinkList_Order(NODE *head);
void Display_LinkList_Order(NODE *head);
void Free_LinkList_Order(NODE *head);

int main()
{
  NODE *head;

  head = Create_LinkList_Order();  //创建有序链表
  if (head == NULL)                //创建失败，则返回
	 return -1;
  printf("Created ordered linked list: ");
  Display_LinkList_order(head);    //输出链表中的值

  Delete_LinkList_Order(head);     //删除有序链表中重复结点
  printf("After deleting duplicate nodes: ");
  Display_LinkList_order(head);    //输出链表中的值

  Free_LinkList_order(head);       //销毁链表
  return 0;
}

//创建降序排列的有序链表
NODE *Create_LinkList_Order()
{
  NODE *head, *pf, *p, *pnew;
  int i, num, data;

  //创建头结点
  head = (NODE *)malloc(sizeof(NODE));
  if (head == NULL)   //创建失败,则返回
  {
    printf("no enough memory!\n");
    return(NULL);
  }
  head->next = NULL;   //头结点的指针域置NULL

  printf("input the number of integers: ");
  scanf("%d", &num);  //输入整数个数
  printf("input %d integers: ", num);

  //将每次输入的数据插入的有序链表中
  for(i = 0; i < num; i++)  
  {
    //为输入的整数创建一个由pnew指向的新数据结点
	scanf("%d", &data);    //输入整数
    pnew = (NODE *)malloc(sizeof(NODE));  //创建一新结点
    if (pnew == NULL)   //创建新结点失败,则返回
	{
      printf("no enough memory!\n");
      return(NULL);
	}
	pnew->data = data;
    pnew->next = NULL;

	//找新数据结点要插入的位置（即前驱结点的指针pf）
    pf = head;        //pf为前驱结点指针
    p = head->next;   //p为当前结点指针
	while(p != NULL && p->data > data)
	{
	  pf = p;
	  p = p->next;
	}

	//将pnew所指的新结点插入到pf所指结点的后面
    pnew->next = p;
    pf->next = pnew;
  }
  return(head);   //返回创建的链表的头指针
}


//删除有序链表中的重复结点
void Delete_LinkList_Order(NODE *head)
{
  NODE *p, *q, *r;

  p = head->next;  //p指向第一个数据结点
  while(p != NULL)
  {
	//删除与p所指结点数据值相同的后继结点
	for(q = p->next; q != NULL && q->data == p->data; )
	{
	  r = q;        //r指向重复结点
	  q = q->next;  //q指向下一个后继结点
	  free(r);      //删除重复结点
	}
	p->next = q;    //调整p所指结点的后继
	p = q;          //p指向下一个结点     
  }
}  


//显示链表中的数据域的值
void Display_LinkList_Order(NODE *head)
{
  NODE *p;

  for(p = head->next; p != NULL; p = p->next)
	 printf("%d ",p->data);
  printf("\n");
}


//销毁链表
void Free_LinkList_Order(NODE *head)
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
