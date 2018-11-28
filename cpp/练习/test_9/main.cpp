#include <iostream>
using namespace std;

class Test
{
    public:
        Test();
        ~Test();
    private:
        int m_data;
        int *m_p;
};

Test::Test()
{
    cout << "Test()" << this << endl;
    m_p = new int;
}

Test::~Test()
{
    cout << "~Test()" << this << endl;
    delete m_p;
}

int main()
{
    Test *p = new Test;
    delete p;
    return 0;
}
