/*This is my fourth C program*/
#include <stdio.h>
#define PI 3.1415926
int main()
{
	float radius, circumference, area;

	printf("Please input a number as the radius,and the circumference as well as teh area of a circle will be rendered\n");
	
	printf("radius = ");
	
	scanf("%f", &radius);
	
	circumference = 2*PI*radius;
	
	area = PI*radius*radius;
	
	printf("circumference = %f\narea = %f", circumference, area);

	return 0;
}
