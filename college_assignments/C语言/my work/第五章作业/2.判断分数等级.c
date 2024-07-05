#include <stdio.h>
int main ()
{
	int grade, s;
	printf("Your score:");
	scanf("%d", &s);
	
	printf("Grade :");

	if(s>=90 && s<=100)
		printf("A\n"); 
		
	else if(s>=80 && s<=89 )
		printf("B\n");
		
    else if(s>=70 && s<=79)
		printf("C\n");
		
	else if(s>=60 && s<=69 )
        printf("D\n");
        
    else if(s>=0 &&  s<=60 )
        printf("F\n");
        
	else 
	    printf("enter data error!\n");
	
	return 0;
	
}





