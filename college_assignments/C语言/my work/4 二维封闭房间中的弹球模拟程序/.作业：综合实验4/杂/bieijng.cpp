#include <stdio.h>
#include <string.h>
#define HEIGHT 24
#define WIDTH 80
int main()
{
	int i, j, k;
	char cWin[HEIGHT][WIDTH];//24 80
	for(i = 0, j = 0; j < 79; j++)
	cWin[i][j] = '-';
	cWin[i][j] = '\n';
	
	for(k = 1; k <= 22; k++)
	{		
		j = 0;
		cWin[k][j] = '!';
		for(j = 1; j < 78; j++)
		cWin[k][j] = ' ';
		cWin[k][j] = '!';
		cWin[k][j+1] = '\n';
	}
	
	for(i = 23, j = 0; j < 79; j++)
	cWin[i][j] = '-';
	cWin[i][j] = '\n';
	
	//for(i = 0; i < 24; i++)
	//for(j = 0; j < 80; j++)
	//	printf("%c", cWin[i][j]);与下面输出字符串等价 
	printf("%s", cWin);
	return 0;
}
