/***********************************
 * 文件名称: main.cpp
 * 文件描述: 
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

///////////////////////////////
// 头文件
#include <iostream>
using namespace std;

class Date
{
    public:
        void Set(int yesr, int month, int day);
        void Print();
    private:
        int m_year;
        int m_month;
        int m_day;
};

///////////////////////////////
// 函数
void Date::Set(int year, int month, int day)
{
    m_year = year;
    m_month = month;
    m_day = day;
}

void Date::Print()
{
    cout << m_year << " " << m_month << " " << m_day <<endl;
}

///////////////////////////////
// 主函数
int main()
{
    
    return 0;
}
