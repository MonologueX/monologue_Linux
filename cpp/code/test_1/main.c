#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    int a = i++;
    cout << "a = i++ =" << a << endl;
    int b = ++a;
    cout << "b = ++a =" << a <<endl;
    int c = a + b;
    cout << "a = i++ =" << a <<endl;
    int d = a?b:c;
    cout << "a?b: = " << d <<endl;
    return 0;
}
