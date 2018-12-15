#include <pthread.h>

// 任务队列
typedef struct condition
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}condition_t;

typedef struct task 
{
    void *(*pfun)(void *); // 目标函数
    void *arg;             // 目标函数参数
    struct task *next;
}task_t;

typedef struct pthreadpool 
{
    condition_t cond; // 同步互斥
    task_t *first;    // 任务队列的队头
    task_t *tail;     // 队尾指针
    int max_thread;   // 最大线程数
    int idle;         // 空闲线程个数
    int counder;      // 线程池当前线程个数 
}pthreadpook_t;

void pthreadpool_init(pthread_t *pool, int max);

void pthreadpool_add(pthread_t *pool, void*(*pf)(void *), void *arg);

void pthreadpool_destroy(pthread_t *pool);

