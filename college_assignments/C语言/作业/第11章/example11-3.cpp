//��������
NODE *Create_LinkList() 
{
  NODE *head, *tail, *pnew;
  int score;

  head = (NODE *)malloc(sizeof(NODE));  //����ͷ�ڵ�
  if (head == NULL)                     //����ʧ��,�򷵻�
  {
    printf("no enough memory!\n");
    return(NULL);
  }  
  head->next = NULL;       //ͷ�ڵ��ָ������NULL
  tail = head;             //��ʼʱβָ��ָ��ͷ�ڵ�

  printf("input the score of students:\n");
  while(1)                 //����ѧ���ɼ���������
  {
    scanf("%d",&score);    //����ɼ�
    if (score < 0)         //�ɼ�Ϊ��,ѭ���˳�
       break;
    pnew =  (NODE *)malloc(sizeof(NODE));  //����һ�½ڵ�
    if (pnew == NULL)      //�����½ڵ�ʧ��,�򷵻�
	{
      printf("no enough memory!\n");
      return(NULL);
	}  
	pnew->score = score;   //�½ڵ������������ĳɼ�
    pnew->next = NULL;     //�½ڵ�ָ������NULL

    tail->next = pnew;     //�½ڵ���뵽����β
    tail = pnew;           //ζָ��ָ��ǰ��β�ڵ�
  }
  return(head);            //���ش����������ͷָ��
}
