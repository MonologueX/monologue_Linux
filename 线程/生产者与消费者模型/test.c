#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <malloc.h>

#define CUSTEM_COUNT 2
#define PRODUCER_COUNT 2

int count = 0;
pthread_cond_t cond;
pthread_mutex_t mutex;

void *custem(void *arg)
{
    int id = *(int*)arg;
    free(arg);
    while (1)
    {
        pthread_mutex_lock(&mutex);
        while (count <= 0)
        {
            printf("%d消费者等待消费\n", id); 
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d消费者开始消费产品%d\n", id, count); 
        sleep(rand()%5);
        printf("%d消费者结束消费%d产品\n", id, count--); 
        pthread_mutex_unlock(&mutex);
        sleep(rand()%2);
    }
}
void *product(void *arg)
{
    int id = *(int*)arg;
    free(arg);
    while (1)
    {
        pthread_mutex_lock(&mutex);
        printf("%d生产者开始生产产品%d\n", id, count); 
        sleep(rand()%6);
        printf("%d生产者结束生产产品%d\n", id, count++); 
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int main()
{
    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);
    pthread_t tid[CUSTEM_COUNT+PRODUCER_COUNT];
    for (size_t i = 0; i < CUSTEM_COUNT; i++)
    {
        int *p = (int*)malloc(sizeof(int));
        *p = i;
        pthread_create(&tid[i], NULL, custem, p);
    }
    for (size_t i = 0; i < PRODUCER_COUNT; i++)
    {
        int *p = (int*)malloc(sizeof(int));
        *p = i;
        pthread_create(&tid[i+CUSTEM_COUNT], NULL, product, p);
    }
    for (size_t i = 0;i < CUSTEM_COUNT+PRODUCER_COUNT; i++)
    {
        pthread_join(tid[i], NULL);
    }
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);
    return 0;
}
