/***********************************
 * 文件名称: myshell.c
 * 文件描述: 迷你shell
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 1024
#define NUM 32

int main()
{
    char cmd[MAX];
    char *myargv[NUM];
    for (;;)
    {
        printf("newshell]>");
        fflush(stdout);
        fgets(cmd, MAX, stdin);
        cmd[strlen(cmd) - 1] = 0;
        printf("%s", cmd);
        int i = 0;
        myargv[i] = strtok(cmd, " ");
        i++;
        while (1)
        {
            char *p = strtok(NULL, " ");
            if (NULL == p)
            {
                myargv[i] = NULL;
                break;
            }
            myargv[i] = p;
            i++;
        }
        pid_t id = fork();
        if (id < 0)
        {
        }
        else if (0 == id)
        {
            execvp(myargv[0], myargv);
        }
        else
        {
            waitpid(id, NULL, 0);
        }
    }
    
    return 0;
}
