#include <stdio.h> 
int main ()
{   
    char  *string = "I love China!";
    printf ("%s\n", string);
    string += 7;
    while (*string)
    {      
        putchar (string[0]);
        string++;
    }
    return 0;
}
