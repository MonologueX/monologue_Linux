#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[], char* env[])
{
  extern char** environ;
  int i = 0;
  while (environ[i] != NULL)
  {
    printf("env[%s]\n", environ[i]);
    i++;
  }
  return 0;
}
