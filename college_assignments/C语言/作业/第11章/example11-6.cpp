//��ʾ�����е��������ֵ
void Display_LinkList(NODE *head)  
{
  NODE *p;

  for(p = head->next; p != NULL; p = p->next)
	 printf("%d ",p->score);
  printf("\n");
}