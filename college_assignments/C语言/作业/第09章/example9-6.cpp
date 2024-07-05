#include  <stdio.h>
	
int main()
{ 
  char  *pstr = "I Love China!"; 

  for(; *pstr != '\0'; pstr++) 
    printf("%c", *pstr);
  return 0;
}
