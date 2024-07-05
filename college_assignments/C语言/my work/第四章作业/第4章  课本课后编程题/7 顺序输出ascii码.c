#include <stdio.h>
int main()
{
	char c;
	c = getchar();
	char x, y;
	x = c - 1;
	y = c + 1;
	printf("%c %c %c", x, c, y);
	printf("\n%d %d %d", x, c, y);
	return 0;
}
