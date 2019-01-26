#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T1, typename T2>

T1 Add(T1 left, T2 right)
{
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
    return left + right;
}

void Test()
{
    cout << Add(1, 2) << endl;
    cout << Add(1.1, 2.2) << endl;
    cout << Add(1, 2.2) << endl;
}

int main()
{
    Test();
    return 0;
}
