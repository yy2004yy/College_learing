#include <stdio.h>
#include <math.h>
int main ()
{
	int n, a, i, W, S;//a��һ������0~9֮�������
	printf("��̼��� a + aa + aaa + ... + aa...a(n �� a)��ֵ��������n��a��ֵ��\n");
	
	printf("n = ");
	scanf("%d", &n);
	printf("a = ");
	scanf("%d", &a);
	
	i = 1;
	S = 0;
	W = 0;
	
	while(i <= n) 
	{
		W = a + W *10;
		S = S + W;
		i++;
	}

	printf("������ֵ��%d", S);
	printf("%d+%d%d+%d%d%d+...+%d%d...%d(%d��%d)��ֵΪ%d", a, a, a, a, a, a, a, a, a, n, a, S);
	return 0;
	
 } 
