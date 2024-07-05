#include <stdio.h>

void print(int w);

int main()
{
  print(3);
  return 0;
}

void print(int w)
{      
  int  i;

  if ( w!=0)
  {     
    print(w-1);
    for(i = 1; i <= w; ++i)
      printf("%d ",w);
    printf("\n");
  }
}
