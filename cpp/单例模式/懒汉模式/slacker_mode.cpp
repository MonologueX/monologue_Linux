#include <iostream>
#include <string.h>
#include <thread>
#include <mutex>

using namespace std;

class Singleton
{
    public:
        static Singleton* GetInstrance();

        class GC
        {
            public:
                ~GC();
        };

    private:
        Singleton();
        Singleton(const Singleton&);
        Singleton& operator=(Singleton const&);

    private:
        static Singleton* volatile m_ps;
        static mutex m_mutex;
        static GC m_gc;
};

Singleton* volatile Singleton::m_ps = nullptr;
mutex Singleton::m_mutex;
Singleton::GC m_gc;

Singleton* Singleton::GetInstrance()
{
    if (nullptr == m_ps)
    {
        m_mutex.lock();
        if (nullptr == m_ps)
        {    
            m_ps = new Singleton();
            cout << "Create success" << endl;
        }
        m_mutex.unlock();
    }
    return m_ps;
}

Singleton::GC::~GC()
{
    if (nullptr == m_ps)
    {
        if (nullptr == m_ps)
        {    
            delete m_ps;
            m_ps = nullptr;
        }
    }
}

Singleton::Singleton()
{}

void func(int a)
{
    Singleton::GetInstrance();
}

int main()
{
    thread t1(func, 10);
    thread t2(func, 10);
    t1.join();
    t2.join();
    cout << Singleton::GetInstrance() << endl;
    cout << Singleton::GetInstrance() << endl;
    return 0;
}
