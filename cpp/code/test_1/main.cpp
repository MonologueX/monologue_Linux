#include <iostream>
using namespace std;

void test_1()
{
    int i = 0;
    int a = i++;
    cout << "a = i++ =" << a << endl;
    cout << "a = " << a <<endl;
    int b = ++a;
    cout << "b = ++a =" << b <<endl;
    cout << "a = " << a <<endl;
    cout << "b = " << b <<endl;
    int c = a + b;
    cout << "c = a+b =" << c <<endl;
    a = 0;
    int d = a?b:c;
    cout << "a?b:c = " << d <<endl;
}

class A
{
    public:
        void fun()
        {
            cout << "hello word" << endl;
        }
    private:
};


void test_2()
{
    A *pa = NULL;
    pa->fun(); 
}

int main()
{
    test_2();   
    return 0;
}
