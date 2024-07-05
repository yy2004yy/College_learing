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

  head = Create_LinkList_Order();  //������������
  if (head == NULL)                //����ʧ�ܣ��򷵻�
	 return -1;
  printf("Created ordered linked list: ");
  Display_LinkList_order(head);    //��������е�ֵ

  Delete_LinkList_Order(head);     //ɾ�������������ظ����
  printf("After deleting duplicate nodes: ");
  Display_LinkList_order(head);    //��������е�ֵ

  Free_LinkList_order(head);       //��������
  return 0;
}

//�����������е���������
NODE *Create_LinkList_Order()
{
  NODE *head, *pf, *p, *pnew;
  int i, num, data;

  //����ͷ���
  head = (NODE *)malloc(sizeof(NODE));
  if (head == NULL)   //����ʧ��,�򷵻�
  {
    printf("no enough memory!\n");
    return(NULL);
  }
  head->next = NULL;   //ͷ����ָ������NULL

  printf("input the number of integers: ");
  scanf("%d", &num);  //������������
  printf("input %d integers: ", num);

  //��ÿ����������ݲ��������������
  for(i = 0; i < num; i++)  
  {
    //Ϊ�������������һ����pnewָ��������ݽ��
	scanf("%d", &data);    //��������
    pnew = (NODE *)malloc(sizeof(NODE));  //����һ�½��
    if (pnew == NULL)   //�����½��ʧ��,�򷵻�
	{
      printf("no enough memory!\n");
      return(NULL);
	}
	pnew->data = data;
    pnew->next = NULL;

	//�������ݽ��Ҫ�����λ�ã���ǰ������ָ��pf��
    pf = head;        //pfΪǰ�����ָ��
    p = head->next;   //pΪ��ǰ���ָ��
	while(p != NULL && p->data > data)
	{
	  pf = p;
	  p = p->next;
	}

	//��pnew��ָ���½����뵽pf��ָ���ĺ���
    pnew->next = p;
    pf->next = pnew;
  }
  return(head);   //���ش����������ͷָ��
}


//ɾ�����������е��ظ����
void Delete_LinkList_Order(NODE *head)
{
  NODE *p, *q, *r;

  p = head->next;  //pָ���һ�����ݽ��
  while(p != NULL)
  {
	//ɾ����p��ָ�������ֵ��ͬ�ĺ�̽��
	for(q = p->next; q != NULL && q->data == p->data; )
	{
	  r = q;        //rָ���ظ����
	  q = q->next;  //qָ����һ����̽��
	  free(r);      //ɾ���ظ����
	}
	p->next = q;    //����p��ָ���ĺ��
	p = q;          //pָ����һ�����     
  }
}  


//��ʾ�����е��������ֵ
void Display_LinkList_Order(NODE *head)
{
  NODE *p;

  for(p = head->next; p != NULL; p = p->next)
	 printf("%d ",p->data);
  printf("\n");
}


//��������
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
