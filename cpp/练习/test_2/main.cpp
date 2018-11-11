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
int main()
{
    const int a = 10;
    int *pa = (int*)&a;

    *pa = 100;

    cout << a << endl;
    cout << *pa << endl;
 
    return 0;
}
