//Ïú»ÙÁ´±í
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