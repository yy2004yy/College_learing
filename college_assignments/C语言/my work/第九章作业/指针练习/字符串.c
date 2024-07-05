#include <stdio.h>
int main()
{
	char str[1000] = "I love China!";
	char *strp;
	strp = str;
	printf("%s\n", str);
	printf("sizeof(str) = %d\n", sizeof(str));
	printf("%s", str);
	return 0;
}
