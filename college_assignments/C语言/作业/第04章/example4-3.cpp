#include <stdio.h>

int main()
{
  double  f = 2.5e5;
	
  printf("  12345678901234567890\n");
  printf("f=%15f--------(f=%%15f)\n",f);
  printf("f=%015f--------(f=%%015f)\n",f);
  printf("f=%-15.0f--------(f=%%-15.0f)\n",f);
  printf("f=%#15.0f--------(f=%%#15.0f)\n",f);
  printf("f=%+15.4f--------(f=%%+15.4f)\n",f);
  printf("f=%15.4E--------(f=%%15.4E)\n",f);
  return 0;
}
