#include <stdio.h>
int main (void)
{
	int a[20], i, n, t;
	n = 0, t = 0;
	
	for(i = 0; i <= 19; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
		if(a[i] >= 0) 
		{
		n++; 
		t = t + a[i];
		}
	}
	
	printf("�Ǹ����ĸ���%d\n", n);
	printf("���зǸ����ĺ�%d\n", t);
	return 0;
 } 
