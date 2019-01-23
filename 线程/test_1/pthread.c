#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *thr_start(void *arg)
{
    while (1)
    {
        printf("This is child thread!!!\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    int ret = 1;
    ret = pthread_create(&tid, NULL, thr_start, NULL);
    if (ret != 0)
    {
        printf("pthread error!!!\n");
        return -1;
    }
    while (1)
    {
        printf("This is main thread!!!\n");
        sleep(1);
    }
    return 0;
}
