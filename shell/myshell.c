/////////////////////////////// 
//  文件名称:myshell 
//  文件描述:myshell-version-1
//  编译环境:Linux
//  作者相关:心文花雨 

///////////////////////////////
// 头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

///////////////////////////////
// 函数 
int ParseArg(char input[], char* output[])
{
  int output_index = 0;
  char* p = strtok(input, " ");
  while (p != NULL) 
  {
    output[output_index++] = p;
    p = strtok(NULL, " ");
  }
  output[output_index] = NULL;
  return output_index;
}

void Run(int argc, char* argv[])
{
  pid_t ret = fork();
  if (ret > 0)
  {
    wait(NULL);
  }
  else if (ret == 0)
  {
    execvp(argv[0], argv);
    perror(argv[0]);
    exit(0);
  }
  else
  {
    perror("fork");
  }
}

///////////////////////////////
// 主函数 
int main()
{
  while(1)
  {
    char buf[1024 * 10] = {0};
    printf("[monlogue@dev]$ ");
    fflush(stdout);
    gets(buf);

    char* argv[100] = {0};
    int argc = ParseArg(buf, argv);

    Run(argc, argv);
  } 
  return 0;
}
