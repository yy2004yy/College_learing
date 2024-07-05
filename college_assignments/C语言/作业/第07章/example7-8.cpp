#include <stdio.h>

#define  IN   1
#define  OUT  0

int main()
{  
  char string[80], c;
  int i, num=0, word = OUT;

  gets(string);
  for(i = 0; (c = string[i]) != '\0'; i++)
	 if (c == ' ')  //ÅÐ¶ÏcÊÇ·ñÎª¿Õ¸ñ
        word=OUT;
	 else 
	   if (word == OUT)
	   {   
		word = IN;
        num++;
	   }
  printf("There are %d words in the line.\n",num);
  return 0;
}
