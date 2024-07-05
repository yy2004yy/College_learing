#include <stdio.h>
#include <string.h>

#define N 3

struct Person{
  char name[20];
  int points; 
};

void swap(int *p1, int *p2);

int main() {
  struct Person leader[N]={{"Li", 3},
                           {"Zhang",10},
                           {"Sun",0}};
  if (leader[0].points < leader[1].points)
    swap(&leader[0].points, &leader[1].points);
  printf("Li:%d, Zhang: %d\n", leader[0].points, leader[1].points);
  return 0;
}

void swap(int *p1, int *p2) {
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
