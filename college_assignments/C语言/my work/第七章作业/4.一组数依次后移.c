#include <stdio.h>
int main (void)
{
	int a[6], i, t, cnt;
	
	for(i = 0; i <= 5; i++)
		scanf("%d", &a[i]);

	for(cnt = 1; cnt <= 5; cnt++)
	{
		t = a[5];
		a[5] = a[4];
		a[4] = a[3];
		a[3] = a[2];
		a[2] = a[1];
		a[1] = a[0];
		a[0] = t;	
	
	for(i = 0; i <= 5; i++)
		printf("%d ", a[i]);
	printf("\n");//每输出一行打印一个'\n' 
	}	
}//示例：5 6 8 1 9 4 '\n' 
