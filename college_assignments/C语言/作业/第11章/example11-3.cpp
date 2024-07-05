//创建链表
NODE *Create_LinkList() 
{
  NODE *head, *tail, *pnew;
  int score;

  head = (NODE *)malloc(sizeof(NODE));  //创建头节点
  if (head == NULL)                     //创建失败,则返回
  {
    printf("no enough memory!\n");
    return(NULL);
  }  
  head->next = NULL;       //头节点的指针域置NULL
  tail = head;             //开始时尾指针指向头节点

  printf("input the score of students:\n");
  while(1)                 //创建学生成绩线性链表
  {
    scanf("%d",&score);    //输入成绩
    if (score < 0)         //成绩为负,循环退出
       break;
    pnew =  (NODE *)malloc(sizeof(NODE));  //创建一新节点
    if (pnew == NULL)      //创建新节点失败,则返回
	{
      printf("no enough memory!\n");
      return(NULL);
	}  
	pnew->score = score;   //新节点数据域放输入的成绩
    pnew->next = NULL;     //新节点指针域置NULL

    tail->next = pnew;     //新节点插入到链表尾
    tail = pnew;           //味指针指向当前的尾节点
  }
  return(head);            //返回创建的链表的头指针
}
