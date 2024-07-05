#include <stdio.h>
#define NUM 10
void getdata(int num1[], int n);
void sort(int num2[], int n);
int main()
{
	int i, num[NUM];
	printf("Please enter 10 integer: \n");
	getdata(num, NUM);
	sort(num, NUM);
	for(i = 0; i < NUM; i++)
		printf("%d ", num[i]);
		
	return 0;
 } 
 
void getdata(int num1[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		scanf("%d", &num1[i]);

}

void sort(int num2[], int n)
{
	int i, j, t, flag;
	for(i = 1; i < n; i++)//n-1´ÎÃ°ÅÝÅÅÐò 
	{
		flag = 0;
		for(j = 0; j < n-i; j++)
			if(num2[j] < num2[j+1])
			{
				t = num2[j];
				num2[j] = num2[j+1];
				num2[j+1] = t;
				flag = 1;
			}
		if(flag == 0) break;
	}
 }
