#include <iostream>

using namespace std;

class Singleton
{
    public:
        static Singleton* GetInstrance()
        {
            return &m_ps;
        }
    private:
        Singleton()
        {}
    private: 
        static Singleton m_ps;
};

Singleton Singleton::m_ps;

int main()
{

    return 0;
}
