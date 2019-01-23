#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

void *thr_start(void *arg)
{
    return "Hello pthread\n";
}

int main()
{
    pthread_t tid;
    int ret = 1;
    ret = pthread_create(&tid, NULL, thr_start, NULL);
    if (ret != 0)
    {
        printf("pthread_create error!!!\n");
        return -1;
    }
    char *ptr;
    pthread_join(tid, (void **)&ptr);
    printf("child tread say: %s\n", ptr);
    return 0;
}
