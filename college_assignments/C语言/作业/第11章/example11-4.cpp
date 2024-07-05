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
