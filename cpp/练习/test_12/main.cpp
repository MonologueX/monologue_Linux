#include <iostream>
using namespace std;

class Singleton
{
    public:
        static Singleton& GetInstrance();
    private:
        Singleton();
        Singleton(const Singleton&) = delete;
    private:
        static Singleton m_innstrance;
};


Singleton& Singleton::GetInstrance()
{
    return m_innstrance;
}

Singleton Singleton::m_innstrance;

int main()
{
    
    return 0;
}
