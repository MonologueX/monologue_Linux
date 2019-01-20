/***********************************
 * 文件名称: mini_shell.c
 * 文件描述: 简单的 mini_shell 1
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <wait.h>

#define MAX 1024
#define NUM 32
 
int main(void)
{
    char cmd[MAX];
    char *myargv[NUM];
    struct passwd *pwd;
    pwd = getpwuid(getuid());
    char *dir = NULL;
    dir = (char *)get_current_dir_name();
    while (1)
    {
        printf("[%s@localhost %s]:" , pwd->pw_name, strrchr(dir,'/')+1);
        fflush(stdout);
        fgets(cmd, MAX, stdin);
        cmd[strlen(cmd)-1] = 0;

        int i = 0;
        myargv[i] = strtok(cmd, " ");
        i++;

        while (1)
        {
            char *p = strtok(NULL, " ");
            if (NULL == p)
            {
                myargv[i] =NULL;
                break;
            }
            myargv[i] = p;
            i++;
        }
        pid_t id = fork();
        if (id < 0)
        {
            ;
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
    return 0 ; 
}
