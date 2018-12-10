/***********************************
 * 文件名称: list.cpp
 * 文件描述: 练习
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
#include <iostream>
using namespace std;

#include <list>
#include <vector>
#include <unistd.h>

template<class T>
void Print(const T& l)
{
    for (auto& e : l)
    {
        cout << e << " ";
    }
    cout <<endl;
}

#if 0
void Test1()
{
    list<int> l1;
    list<int> l2(10, 5);
    vector<int> v{1, 2, 3, 4, 5};
    list<int> l3(v.begin(), v.end());
    int array[] = {1, 2, 3, 4, 5, 6};
    list<int> l4(array, array + sizeof(array)/sizeof(array[0]));
    list<int> l5{1, 2, 3, 4, 5};

    Print(l2);
    Print(l3);
    Print(l4);
    Print(l5);

    list<int>::iterator it1 = l5.begin();
    while (it1 != l5.end())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;

    auto it2 = l5.rbegin();
    while (it2 != l5.rend())
    {
        cout << *it2 << " ";
        ++it2;
    }
    cout << endl;

}

void Test2()
{
    list<int> l;
    l.insert(l.begin(), 1);
    l.insert(l.begin(), 2);
    l.insert(l.begin(), 3);
    Print(l);

    int array[] = {6, 6, 6, 6, 6};
    l.insert(find(l.begin(), l.end(), 2), array, array + sizeof(array)/array[0]);
    Print(l);
    l.erase(--l.end());
    Print(l);
    auto it = l.begin();
    while (it != l.end())
    {
        it = l.erase(it);
    }
    Print(l);
}
#endif

bool IsEven(int data)
{
    return (0 == (data & 0x01));
}

class Mod
{
    public:
        bool operator()(int data)
        {
            return 0 == (data % 3);
        }
    private:
};


void Test()
{
    list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    l.remove_if(IsEven);
    Print(l);
    l.remove_if(Mod());
    Print(l);
}

int main()
{
    Test();    
    return 0;
}
