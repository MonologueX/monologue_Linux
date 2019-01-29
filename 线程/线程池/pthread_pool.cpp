/***********************************
 * 文件名称: pthresd_pool.cpp
 * 文件描述: 线程池
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

typedef int (*HandlerTask_t)(int x, int y, int op);
class Task
{
    public:
        Task(int x = -1, int y = -1, int op = -1)
            :m_x(x), m_y(y), m_op(op)
        {

        }

        void Register(HandlerTask_t handler_)
        {
            handler = handler_;
        }

        void Run()
        {
            int ret = handler(m_x, m_y, m_op);
            const char *op_ = "+-*/";
            std::cout << "thread ["<< pthread_self() << "] handlerresult: " << m_x << op_[m_op] << m_y << " = " << ret << std::endl;
        }

        ~Task()
        {

        }

    private:
        int m_x;
        int m_y;
        int m_op;
        HandlerTask_t handler;
};

class ThreadPool
{
    public:
        ThreadPool(int num_ = 5):thread_nums(num_), idle_nums(0)
        {
            pthread_mutex_init(&lock, NULL);
            pthread_cond_init(&cond, NULL);
        }

        static void *ThreadRotinue(void *arg)
        {
            pthread_detach(pthread_self());
            ThreadPool *tp = (ThreadPool*)arg;
            for ( ; ;)
            {
                tp->LockQueue();
                while (tp->QueueIsEmpty())
                {
                    tp->ThreadIdle();
                }
                Task t;
                tp->PopTask(t);
                tp->UnlockQueue();
                t.Run();
            }
        }

        void InitThreadPool()
        {
            pthread_t t;
            for (auto i = 0; i < thread_nums; i++)
            {
                pthread_create(&t, NULL, ThreadRotinue, this);
            }
        }

        void PushTask(const Task &t)
        {
            LockQueue();
            task_queue.push(t);
            WakeupThread();
            UnlockQueue();
        }

        ~ThreadPool()
        {
            pthread_mutex_destroy(&lock);
            pthread_cond_destroy(&cond);
        }
    public:
        void LockQueue()
        {
            pthread_mutex_lock(&lock);
        }

        void UnlockQueue()
        {
            pthread_mutex_unlock(&lock);
        }

        bool QueueIsEmpty()
        {
            return task_queue.size() == 0 ? true :false;
        }

        void ThreadIdle()
        {
            idle_nums++;
            pthread_cond_wait(&cond, &lock);
            idle_nums--;
        }

        void WakeupThread()
        {
            pthread_cond_signal(&cond);
        }

        void PopTask(Task &t)
        {
            t = task_queue.front();
            task_queue.pop();
        }

    private:
        int thread_nums;
        int idle_nums;
        std::queue<Task> task_queue;
        pthread_mutex_t lock;
        pthread_cond_t cond;
};

int cal(int x, int y, int op)
{
    int ret = -1;
    switch(op)
    {
        case 0:
            ret = x + y;
            break;
        case 1:
            ret = x - y;
            break;
        case 2:
            ret = x * y;
            break;
        case 3:
            ret = x / y;
            break;
        default:
            std::cout << "cal error!" << std::endl;
            break;
    }
    return ret;
}

int main()
{
    ThreadPool tp;
    tp.InitThreadPool();
    srand((unsigned long)time(NULL));
    for (;;)
    {
        sleep(1);
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        int op = rand() % 4;
        Task t(x, y, op);
        t.Register(cal);
        tp.PushTask(t);
    }
    return 0;
}
