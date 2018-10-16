#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

void ParseArg(char input[], char* output[])
{
  
}

int main()
{
  while(1)
  {
    char buf[1024 * 10] = {0};
    printf("[monlogue@dev]$ ");
    fflush(stdout);
    gets(buf);

    char* argv[100] = {0};
    ParseArgv(buf, argv);

    Run(argv);
  } 
  return 0;
}
