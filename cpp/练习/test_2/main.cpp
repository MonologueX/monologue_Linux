/*
 * 文件名称:main.c
 * 文件描述:练习
 * 编译环境:Linux 
 * 作者相关:心文花雨 
*/ 

///////////////////////////////
// 头文件
#include <iostream>
using namespace std;

#define Max(a, b) ((a)>(b)?(a):(b))

///////////////////////////////
// 函数
//int main()
//{
//    int a1 = 10;
//    int a2 = 20;
//
//    cout << Max(a1, ++a2) << endl;
//
//    return 0;
//}

int Add(int a, int b)
{
    return a + b;
}

//inline int Add(int a, int b)
//{
//    return a + b;
//}

//int main()
//{
//    int a = 1;
//    int b = 2;
//    int c = Add(a, b);
//    cout << c << endl;
//
//    return 0;
//}

///////////////////////////////
// const 修饰常量
// & 具有宏的属性 替换

//int main()
//{
//    const int a = 10;
//    int *pa = (int*)&a;
//
//    *pa = 100;
//
//    cout << a << endl;
//    cout << *pa << endl;
// 
//    return 0;
//}

//int main()
//{
//    int a = 10;
//    int b = 20;
//    auto c = 'c';
//    auto d = 1.5;
//    auto ret = fun();
//    cout << typeid(a).name() << endl;
//    cout << typeid(b).name() << endl;
//    cout << typeid(c).name() << endl;
//    cout << typeid(d).name() << endl;
//    // auto 要初始化
//    //auto e;
//    return 0;
//}

//int main()
//{
//    int a = 10;
//    auto pa1 = &a;
//    *pa1 = 20;
//
//    auto *pa2 = &a;
//    *pa2 = 30;
//
//    auto &ra = a;
//    ra = 40;
//
//    return 0;
//}

//int main()
//{
//    int array[] = {1, 2, 3, 4, 5, 6, 7};
//    for (auto &e : array)
//    {
//        e *= 2;
//    }
//    for (auto &e : array)
//    {
//        cout << e << " " << endl;
//    }
//    cout << endl;
//    return 0;
//}


//int main()
//{
//   // 错误
//   // int *p;
//   // for (auto &e : p)
//   // {
//   //     cout << p <<endl;
//   // return 0;
//}

void Testfunc(int a)
{
    cout << "void Testfunc(int a)" << endl;
}

void Testfunc(int *a)
{
    cout << "void Testfunc(int *a)" << endl;
}

int main()
{
    Testfunc(0);
    Testfunc(nullptr);
    return 0;
}
