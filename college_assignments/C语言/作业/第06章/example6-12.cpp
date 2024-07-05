#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num1, num2;  
  int n, s, r;     
  int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0;
  int count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;

  printf("input two integer: ");
  scanf("%d%d", &num1, &num2);
  if (num1 < 0 || num2 < 0 || num1 > num2)
  {
	printf("input error!\n");
	exit(-1);
  }

  for(n = num1; n <= num2; n++)
  {
	s = n;
	do
	{
	  r = s % 10;
	  switch (r)
	  {
	    case 0: count0++;  break;
	    case 1: count1++;  break;
	    case 2: count2++;  break;
	    case 3: count3++;  break;
	    case 4: count4++;  break;
	    case 5: count5++;  break;
	    case 6: count6++;  break;
	    case 7: count7++;  break;
	    case 8: count8++;  break;
	    case 9: count9++;  break;
	  }
      s = s / 10;
	} while(s != 0); 
  }

  printf("0 -- %-4d  1 -- %-4d  2 -- %-4d  3 -- %-4d\n", count0, count1, count2, count3);
  printf("4 -- %-4d  5 -- %-4d  6 -- %-4d  7 -- %-4d\n", count4, count5, count6, count7);
  printf("8 -- %-4d  9 -- %-4d\n", count8, count9);
  return 0;
}
