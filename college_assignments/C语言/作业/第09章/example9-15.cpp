#include <stdio.h>

int add(int a,int b);
int sub(int a,int b);
int max(int a,int b);
int min(int a,int b);

int main()
{
    int a,b,i,k;
	int (*func[4])(int,int) = {add,sub,max,min};
    
	printf("select operator(0-add,1-sub,2-max,3-min): ");
	scanf("%d",&i);
    printf("intput number(a,b): ");
	scanf("%d%d",&a,&b);
    k = func[i](a,b);
    printf("the result: %d\n",k);
	return 0;
}

int add(int a,int b)
{
  return(a+b);
}

int sub(int a,int b)
{
  return(a-b);
}

int max(int a,int b)
{
  return(a > b? a : b);
}

int min(int a,int b)
{
  return(a < b? a : b);
}