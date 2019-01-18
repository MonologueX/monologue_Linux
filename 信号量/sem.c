/***********************************
 * 文件名称: sem.c
 * 文件描述: 信号量互斥
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define IPC_KEY 0x12345678

union semun 
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

void sem_P(int id)
{
    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;
    semop(id, &buf, 1);
}
void sem_V(int id)
{
    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = 1;
    buf.sem_flg = SEM_UNDO;
    semop(id, &buf, 1);
}

int main()
{
    int pid = -1;
    // 1.创建信号量
    int semid = semget(IPC_KEY, 1, IPC_CREAT | 0664);
    if (semid < 0)
    {
        perror("semget error");
        return -1;
    }
    // 2.设置信号量初值
    // 只能设置一次，不能重复设置
    union semun un;
    un.val = 1;
    semctl(semid, 0, SETVAL, un);
    pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        exit(-1);
    }
    else if (0 == pid)
    {
        sleep(1);
        printf("child create success!!!\n");
        while (1)
        {
            sem_P(semid);
            printf("A");
            fflush(stdout);
            usleep(1000);
            printf("A ");
            fflush(stdout);
            sem_V(semid);
        }
    }
    else 
    {
        while (1)
        {
            sem_P(semid);
            printf("B");
            fflush(stdout);
            usleep(1000);
            printf("B ");
            fflush(stdout);
            sem_V(semid);
            usleep(100);
        }
    }
    return 0;
}
