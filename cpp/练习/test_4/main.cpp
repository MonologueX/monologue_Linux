/***********************************
 * 文件名称: main.cpp
 * 文件描述: 练习
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

///////////////////////////////
// 头文件
#include <iostream>
using namespace std;

class Data
{
    public:
        void Set(int year, int month, int day);
        void Print();

    private:
        int m_year;
        int m_month;
        int m_day;
};

///////////////////////////////
// 函数接口
void Data::Set(int year, int month, int day)
{
    m_year = year;
    m_month = month;
    m_day = day;
}

/*
 * void Data::Set(Data *this, int year, int month, int day)
 * {
 *      ...
 * }
 * 类型：*const
 * this 指针只能在成员函数内使用
 * 不会影响 sizeof
 * 第一个隐藏的指针, 通过 ecx 自动传递
*/ 

void Data::Print()
{
    cout << m_year << " " << m_month << " " << m_day << endl;
}

///////////////////////////////
// 主函数
int main()
{
    Data d1;
    d1.Set(2018, 11, 13);
    d1.Print();

    return 0;
}
