#include <stdio.h>
#include <conio.h>
#include <ctype.h>

sum();  //����sum������ԭ��

int main()
{
  int tot;
  
  tot = sum();   //����sum����
  if (tot == -1)
     printf("\nnot select!\n");
  else
	 printf("\nthe result is : %d\n",tot);
  return 0;
}

 sum()   //�����Ķ���
{
  int i,tot = 0;
  char key;
  
  key = getche();
  if (key != '0' && key != '1')
      return(-1);

  for(i = (key == '0') ? 2 : 1; i <= 100; i += 2)
	  tot += i; 
  return(tot);
}
