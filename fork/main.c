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
    int status;
    wait(&status);
    // printf("status = %d\n", status);
    if (status & 0xff)
    {
      printf("进程异常终止！ 信号 = %d\n", status & 0x7f);
    } 
    else 
    {
      printf("进程正常终止！ 退出码 = %d\n", (status >> 8) & 0xff);
    }
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
