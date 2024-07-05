#include <stdio.h>

#define  NULL   0

int main()
{
  char **p;
  char *name[] = {"hello","good","world","bye",""};

  p = name + 1;
  printf("%X %s  ", *p, *p);
  p += 2;
  while(**p != NULL)
    printf("%s\n",*p++);
  return 0;
}

