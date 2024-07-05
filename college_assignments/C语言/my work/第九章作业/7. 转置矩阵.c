#include <stdio.h>
int main()
{
	void transpose(int s1[3][3]);
	int i, j, a[3][3]; 
	
	printf("Please input a 3*3 matrix: \n");
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
		scanf("%d", *(a+i) + j);//相当于scanf("%d", &a[i][j])；
	transpose(a);
	return 0;
}

void transpose(int s1[3][3])
{
	int b[3][3], i, j;
	for(i = 0; i < 3;i++)
		for(j = 0; j < 3; j++)
		*(*(b+i)+j) = *(*(s1+j)+i);
	
	printf("The transposed matrix is :\n");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		printf("%d ", *(*(b+i)+j));//相当于printf("%d", b[i][j])； 
		printf("\n");
	}	
}

