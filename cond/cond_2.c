/***********************************
 * 文件名称: cond_2.c
 * 文件描述: 同步
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int have_goods = 0;
pthread_cond_t sale_cond;
pthread_cond_t buy_cond;
pthread_mutex_t mutex;

void *sale_goods(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (1 == have_goods)
        {
            pthread_cond_wait(&sale_cond, &mutex);
        }
        printf("Produce goods!!!\n");
        have_goods = 1;
        pthread_mutex_unlock(&mutex);
        // sleep(1);
        pthread_cond_signal(&buy_cond);
    }
    return NULL;
}

void *buy_goods(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (have_goods == 0)
        {
            pthread_cond_wait(&buy_cond, &mutex);
            // usleep(1000);
            // continue;
        }
        printf("Buy goods!!!\n");
        have_goods = 0;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&sale_cond);
    }
    return NULL;
}

int main()
{
    pthread_t tid1, tid2;
    pthread_cond_init(&sale_cond, NULL);
    pthread_cond_init(&buy_cond, NULL);
    pthread_mutex_init(&mutex, NULL);
    int ret;
    ret = pthread_create(&tid1, NULL, sale_goods, NULL);
    if (ret != 0)
    {
        printf("create pthread error!!!\n");
        return -1;
    }
    ret = pthread_create(&tid1, NULL, buy_goods, NULL);
    if (ret != 0)
    {
        printf("create pthread error!!!\n");
        return -1;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_cond_destroy(&sale_cond);
    pthread_cond_destroy(&buy_cond);
    pthread_mutex_destroy(&mutex);
    return 0;
}
