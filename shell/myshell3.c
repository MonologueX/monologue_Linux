/////////////////////////////// 
// 文件名称:myshell3.c
// 文件描述:修改
// 编译环境:Linux
// 作者相关:心文花雨 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <string.h>
#include <pwd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

void Parse(char* input, char* output[]) // 用于将路径进行切分，最后一个/后面为当前路径
{
    char* p = strtok(input,"/");
    int i = 0;
    while(p!= NULL)
    {
        output[i++] = p;
        p=strtok(NULL,"/");
    }
}

void ParseArg(char* input, char* output[]) // 用于对输入的命令进行切分
{
    char* p = strtok(input," ");
    int output_size = 0;
    while(p != NULL)
    {
        output[output_size++] = p;
        p = strtok(NULL," ");
    }
    output[output_size] = NULL;
}

void Exec(char* argv[]) // 创建子进程执行进程程序替换
{
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork()");
    }
    else if(pid == 0)
    {
        // 重定向
        int i = 0;
        for(i =0; argv[i] != NULL; ++i)
        {
            if (strcmp(argv[i], ">") == 0)
            {
                if (argv[i+1] == NULL)
                {
                    perror("command '>'[option]?"),exit(1);
                }
                argv[i] = NULL; 
                int fd = open(argv[i+1], O_RDWR|O_CREAT|O_TRUNC, 0664);
                if (fd == -1)
                {
                    perror("open"),exit(1);
                }
                dup2(fd, 1);
                close(fd);
            }
        }
        execvp(argv[0],argv);
        perror("execvp()");
        exit(0);
    }
    else
    {
        wait(NULL);
    }
 }

int main()
{
    while(1)
    {
        //获得当前路径
        char path[100] = {0};
        getcwd(path,sizeof(path)); //getcwd获得的是绝对路径(path里面存放的是绝对路径)
        char* path2[100] = {0}; 
        Parse(path,path2);

        char* path3 = NULL; 
        // path里面为绝对路径，将path按照/进行分割，分割的结果保存在path2里面
        // path3里面保存最后一个字符串，即相对路>径
        int i = 0;
        while(path2[i] !=NULL)
        {
            path3= path2[i];
            i++;
        }

        struct passwd *pwd;
        pwd = getpwuid(getuid());

        //获得主机名
        char hostname[100] ={0};
        gethostname(hostname,sizeof(hostname));
        printf("[%s@%s %s MyShell]",pwd->pw_name,hostname,path3);
        fflush(stdout);

        //从标准输入读取字符串
        char buf[1024] = {0};
        gets(buf);

        //解析字符串，解析出指令和参数
        char* argv[100] = {};
        ParseArg(buf,argv);

        //子进程执行exec函数，将这个过程封装在Exec函数里
         Exec(argv);
    }
    return 0;
}
