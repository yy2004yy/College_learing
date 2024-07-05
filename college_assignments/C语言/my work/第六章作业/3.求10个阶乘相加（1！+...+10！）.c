#include <stdio.h>
int main()
{
	int n, k, w, i;
	
	k = 1;
	i = 1;
	w = 1;
	
	while(i < 10)
	{
		k = k*(i + 1);
		w = w + k;
		i++;
	}
	
	printf("1! + 2! + ... + 10! = %d", w );
}
