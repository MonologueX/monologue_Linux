/***********************************
 * 文件名称: cond.c
 * 文件描述: 条件变量基础使用
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int g_food = 0;
pthread_cond_t cond;
pthread_mutex_t mutex;

void *sale_food(void *arg)
{
    while (1)
    {
        // 加锁
        pthread_mutex_lock(&mutex);

        printf("Produce food!\n");
        g_food = 1;
        /*
         * 函数名: int pthread_cond_broadcast(pthread_cond_t *cond);
         * 函数说明: 广播通知
         * 函数名: int pthread_cond_signal(pthread_cond_t *cond);
         * 函数说明: 通知一个
        */
        pthread_cond_signal(&cond);
        // 解锁
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *eat_food(void *arg)
{
    while (1)
    {
        // 加锁
        pthread_mutex_lock(&mutex);
        while (0 == g_food)
        {
            /*
             * 函数名:int pthread_cond_timedwait(pthread_cond_t *restrict cond,
             *              pthread_mutex_t *restrict mutex,
             *              const struct timespec *restrict abstime);
             *        int pthread_cond_wait(pthread_cond_t *restrict cond,
             *              trict mutex);
             * 函数功能: 等待在条件变量上 
             * 参数: cond: 等待在指定条件变量上
             *       mutex: 互斥锁
            */
            
            //////////////////////////////////////////////////  
            // 为了保护条件的修改，我们使用互斥锁
            // 如果加锁之后，条件不满足会陷入休眠，则造成死锁
            // 因此需要在休眠前解锁
            // 注意：解锁和休眠是原子操作
            // 否则如果有人在解锁后直接条件修改完毕，通知线程
            // 那么这个通知将会失效，导致休眠，从而永久等待
            
            pthread_cond_wait(&cond, &mutex);
            ////////////////////////////////////////////////
            // 被唤醒，代表条件满足，继续操作，需要再次加锁
            // 注意此次加锁不会因为 锁已被别人获取而等待
        }
        printf("have a food!\n");
        g_food = 0;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t tid1, tid2;
    int ret;
    /*
     * 函数名：int pthread_cond_init(pthread_cond_t *restrict cond,
     *                               const pthread_condattr_t *restrict attr);
     *         pthread_cond_t cond = PTHREAD_COND_INITIALIZER
     * 函数功能：条件变量的初始化
     * 参数：cond: 要初始化的条件变量
     *       attr: 条件变量的属性
    */
    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);
    ret = pthread_create(&tid1, NULL, sale_food, NULL);
    if (ret != 0)
    {
        printf("create pthread error!!!\n");
        return -1;
    }
    ret = pthread_create(&tid1, NULL, eat_food, NULL);
    if (ret != 0)
    {
        printf("create pthread error!!!\n");
        return -1;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    /*
     * 函数名: int pthread_cond_destroy(pthread_cond_t *cond);
     * 函数功能: 条件变量的销毁
    */
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);
    return 0;
}
