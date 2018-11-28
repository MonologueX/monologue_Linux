/***********************************
 * 文件名称: main.cpp
 * 文件描述: 模板
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
#include <iostream>
using namespace std;
#include <unistd.h>

template<typename T>
T Add(T left, T right)
{
    return left + right;
}

int main()
{
    cout << Add(2, 3) << endl;
    cout << Add(2.4, 3.5) << endl;
    cout << Add(2, (int)3.5) << endl;
    return 0;
}
