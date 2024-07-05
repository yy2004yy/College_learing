#include <stdio.h>
int main()
{
	float a;
	double b, c;

	a = 123.456789;
	b = a;
	c = 123.456789;

	printf("%f %lf %lf", a, b, c);
	return 0;

}
