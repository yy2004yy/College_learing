//显示链表中的数据域的值
void Display_LinkList(NODE *head)  
{
  NODE *p;

  for(p = head->next; p != NULL; p = p->next)
	 printf("%d ",p->score);
  printf("\n");
}