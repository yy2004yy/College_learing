//ɾ�������еĵ�i���ڵ�
void Delete_LinkList(NODE *head,int i)  
{
  NODE *p,*q;
  int j;

  if (i == 0)
	return;

  p = head;
  for(j = 1; j < i && p->next != NULL; j++)  //��pָ��Ҫɾ���ĵ�i���ڵ��ǰ���ڵ�
     p = p->next;
  if (p->next == NULL)  //���������е�i���ڵ㲻����
  {
	printf("the %d node not foundt!\n",i);
	return;
  }
  q = p->next;        //qָ���ɾ���Ľڵ�i
  p->next = q->next ; //ɾ���ڵ�i
  free(q);
}  