#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

void StrInt()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int>::iterator vit = v.begin();
    cout << *vit << " ";
    while (vit != v.end())
    {
        cout << *vit << " ";
        ++vit; 
    }
    cout << endl;
    list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30); 
    list<int>::iterator lit = l.begin();
    cout << *vit << " ";
    while (lit != l.end())
    {
        cout << *vit << " ";
        ++lit; 
    }
    cout << endl;
}

void Test1()
{
    wstring ws(L"hello Linux");
    cout << ws.max_size() << endl;
    cout <<ws.c_str() << endl;
}

void Test()
{
    string s;
    size_t sz = s.capacity();
    cout << "making a grow: " << endl;
    for (int i = 0; i < 100; ++i)
    {
        s.push_back('c');
        if (sz != s.capacity())
        {
            sz = s.capacity();
            cout << "capacity changed:" << sz << endl;
        }
    }
}

int main()
{
    Test();   
    return 0;
}
