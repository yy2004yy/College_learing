#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, n;
	char *p;
	scanf("%d", &n);
	p = (char*)malloc((n+1)*sizeof(char));
	if(p == NULL)
	{
		printf("Insufficient memory available.");
		exit(-1);
	}
	for(i = 0; i < n; i++)
		*(p+i) = 'A'+i;
	*(p+n) = '\0';
	puts(p);
	free(p);
}
