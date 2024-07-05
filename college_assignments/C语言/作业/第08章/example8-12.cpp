#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main( )
{
  char ch;

  printf ("Enter a character: ");
  ch = getche( );
  printf("\n");
  if (iscntrl(ch))  
	 printf ("The character is a control character\n");
  else if (isdigit(ch))   
	      printf ("The character is a digit\n");
  else if (isupper(ch)) {
          printf("The character is a capital letter\n");
	      printf("lower letter is %c\n", tolower(ch)); }
  else if (islower(ch)) {
	      printf ("The character is a lower letter\n");
	      printf("capital letter is %c\n", toupper(ch)); }
  else printf ("The character is other character\n");
  return 0;
}