#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  printf("=================\n");
  // execl("/usr/bin/ls", "ls", "-l", "/", NULL);
  // execlp("ls", "ls", "-l", "/", NULL);
  char* env[] = {"AAAA = aaaa", NULL};
  execle("./test1", "./test1", NULL, env);
  char* argv[] = {"ls", "-l", "/", NULL};
  execv("/usr/bin/ls", argv);
  return 0;
}
