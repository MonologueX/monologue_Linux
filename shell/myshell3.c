/////////////////////////////// 
// �ļ�����:myshell3.c
// �ļ�����:�޸�
// ���뻷��:Linux
// �������:���Ļ��� 

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

void Parse(char* input, char* output[]) // ���ڽ�·�������з֣����һ��/����Ϊ��ǰ·��
{
    char* p = strtok(input,"/");
    int i = 0;
    while(p!= NULL)
    {
        output[i++] = p;
        p=strtok(NULL,"/");
    }
}

void ParseArg(char* input, char* output[]) // ���ڶ��������������з�
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

void Exec(char* argv[]) // �����ӽ���ִ�н��̳����滻
{
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork()");
    }
    else if(pid == 0)
    {
        // �ض���
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
        //��õ�ǰ·��
        char path[100] = {0};
        getcwd(path,sizeof(path)); //getcwd��õ��Ǿ���·��(path�����ŵ��Ǿ���·��)
        char* path2[100] = {0}; 
        Parse(path,path2);

        char* path3 = NULL; 
        // path����Ϊ����·������path����/���зָ�ָ�Ľ��������path2����
        // path3���汣�����һ���ַ����������·>��
        int i = 0;
        while(path2[i] !=NULL)
        {
            path3= path2[i];
            i++;
        }

        struct passwd *pwd;
        pwd = getpwuid(getuid());

        //���������
        char hostname[100] ={0};
        gethostname(hostname,sizeof(hostname));
        printf("[%s@%s %s MyShell]",pwd->pw_name,hostname,path3);
        fflush(stdout);

        //�ӱ�׼�����ȡ�ַ���
        char buf[1024] = {0};
        gets(buf);

        //�����ַ�����������ָ��Ͳ���
        char* argv[100] = {};
        ParseArg(buf,argv);

        //�ӽ���ִ��exec��������������̷�װ��Exec������
         Exec(argv);
    }
    return 0;
}
