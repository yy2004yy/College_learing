#include <stdio.h>
#include <math.h>

int main()
{
  int s = 1;
  float n = 1.0, t = 1, pi = 0;

  while (fabs(t) >= 1e-6)
  {
    pi = pi + t;
	n += 2;
	s = -s;
	t = s / n;
  }
  pi *= 4;
  printf("pi = %.6f\n", pi);
  return 0;
}