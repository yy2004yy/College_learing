#include <stdio.h>

int main()
{    
  int i, a, num = 0;
  float sum = 0;

  for(i = 0; i < 10; i++)
  {  
	scanf("%d",&a);
	if(a <= 0) continue;
	num++;
	sum += a;
  }
  printf("%d plus integer's sum: %.0f\n", num, sum);
  printf("average value: %.2f\n",sum / num);
  return 0;
}
