/////////////////////////////// 
// 文件名称:test_1
// 文件描述:练习
// 编译环境:Linux
// 作者相关:心文花雨 
#include <iostream>
#include <stdio.h>

using namespace std;

//int Add(int left, int right)
//{
//    return left + right;
//}
//
//double Add(double left, double right)
//{
//    return left + right;
//}
//
//int main()
//{
//    printf("%.2f\n", Add(1.2, 3.2));
//    printf("%d\n", Add(1, 3));
//}

//int main()
//{
//    int a = 10;
//    int & ra = a;
//
//    ra = 20;
//    
//    cout << a << endl;
//    cout << ra << endl;
//
//    cout << &a << endl;
//    cout << &ra << endl;
//    return 0;
//}

//int main()
//{
//    const int a = 10;
//    const int& ra = a;
//    const int& b = 10;
//    double d = 1.4;
//    const int& rd = d; //rd 为临时变量 
//    
//    return 0;
//}

//void Swap(int& left, int &right)
//{
//    int temp = left;
//    left = right;
//    right = temp;
//}
//
//int main()
//{
//    int a = 10;
//    int b = 20;
//    Swap(a, b);
//    cout << a << endl;
//    cout << b << endl;
//    return 0;
//}

int& TestFunc()
{
    int a = 10;
    return a;
}

int main()
{
    int& b = TestFunc();
    cout << b << endl;
    cout << &b << endl;
    cout << b << endl;
    cout << &b << endl;
    cout << b << endl;
    cout << &b << endl;
     
    return 0;
}
