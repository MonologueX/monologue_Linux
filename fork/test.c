#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t ret = fork();
  if (ret == 0)
  {
    exit(0);
  } 
  ret = fork();
  if (ret == 0)
  {
    exit(0);
  }

  // waitpid(-1, NULL, 0);
  // waitpid(-1, NULL, 0);
  while(1)
  {
    pid_t ret = waitpid(-1, NULL, WNOHANG);
    if (ret < 0)
    {
      break; 
    } 
    // TODO
  } 
  while(1)
  {
    sleep(1);
  }
  return 0;
}
