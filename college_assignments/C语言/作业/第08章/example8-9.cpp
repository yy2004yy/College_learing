#include <stdio.h>

long fact(int n);

int main()
{
  int n;
  long L;

  scanf("%d",&n);
  L = fact(n);
  printf("%d! = %ld\n",n,L);
  return 0;
}

long fact(int n)
{
  long L;

  if (n == 1)
	 return(1);
  L = n * fact(n-1);
  return(L);

}