//������ĵ�i���ڵ�����һ�½ڵ�
void Insert_LinkList(NODE *head,NODE *pnew,int i)  
{
  NODE *p;
  int j;

  p = head;
  for(j = 0; j < i && p != NULL; j++)  //��pָ��Ҫ����ĵ�i���ڵ�
     p = p->next;
  if (p == NULL)  //���������е�i���ڵ㲻����
  {
	printf("the %d node not foundt!\n",i);
	return;
  }

  pnew->next = p->next ;  //������ڵ��ָ����ָ���i���ڵ�ĺ�̽ڵ�
  p->next = pnew;         //����i���ڵ��ָ����ָ�����ڵ�
}  
