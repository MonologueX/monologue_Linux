#include<stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
  int i = 0;
  for (; i< 2; i++)
  {
    printf("a");
    fork();
  }
  return 0;
}
