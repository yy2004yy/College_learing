#include <stdio.h>
#include <string.h>
int main ()
{
	char str1[200], str2[200], i, j, k, delta;
	
	printf("ÇëÊäÈëÁ½ĞĞ×Ö·û´®£º\n");
	printf("string 1:"); 
	scanf("%s", &str1);//gets(str1);
	printf("string 2:"); 
	scanf("%s", &str2);//gets(str2);
	
	i = strcmp(str1, str2); 
	if(i == 0)
	printf("%d", i);
	else
	{
		for (j = 0, k = 0;; j++, k++ )
		{
			if(str1[j] == str2[k] )
			continue;
			else
			{
			delta = str1[j] - str2[k];
			printf("%d\n", delta);
			break;
			}
		}
	}
	return 0; 
 } 	
