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