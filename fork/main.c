#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  pid_t ret = fork();
  if (ret > 0)
  {
    printf("father = %d\n", getpid());
    int status = 0;
    wait(&status);
    printf("status = %d\n", status);
    while (1) 
    {
      sleep(1);
    }
  }
  else if (ret == 0)
  {
    printf("child = %d\n", getpid());
    exit(0);
  }
  else 
  {
    perror("fork");
  }
  return 0;
}
