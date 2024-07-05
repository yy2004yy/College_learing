#include <stdio.h>

void hanio(int n, char A, char B, char C);
void move(char x, char y);

int main()
{
  int n;

  printf("input the number of diskes: ");
  scanf("%d", &n);
  printf("the step to moving %d diskes:\n", n);
  hanio(n, 'A', 'B', 'C');
  return 0;
}

void hanio(int n, char A, char B, char C)
{
  if (n == 1)
	 move(A, C);
  else
  {
	hanio(n-1, A, C, B);
	move(A, C);
	hanio(n-1, B, A, C);
  }
}

void move(char x, char y)
{
  printf("%c -----> %c\n",x,y);
}