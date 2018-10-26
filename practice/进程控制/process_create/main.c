#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int process_create(int(*func)(), const char *file, char *argv[])
{
  int ret = 0;
  pid_t pid = fork();
  if (pid == 0)
  {
    ret = func(file, argv);
    if (ret == -1)
    {
      
    }
  }
  else
  {

  }
}

int main()
{
  
  return 0;
}
