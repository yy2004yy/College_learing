//������
#include "head.h"
 
void main()
{
	int n,p=0;
 
 
	printf("�����뵯��ĸ���:");
	scanf("%d", &n);
	
	if (n < 1)
		n = 1;
	else if (n > NUM) 
		n = NUM;
	struct BALL b[NUM];
	srand(time(NULL));
	initBall(b, n);
	redrawCWin(b, n);
	while(1)
	{
		system("CLS");	
		p+=moveBall(b, n,p);
		printf ("��ش�����%d",p);
		redrawCWin(b, n);
		delay(50);
		
	}
 
}
