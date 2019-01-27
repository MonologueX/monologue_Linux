/***********************************
 * 文件名称: vector.cpp
 * 文件描述: 练习
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
#include <iostream>
using namespace std;

#include <vector>

class Date
{
    public:
        Date(int year = 1900, int month = 1, int day = 1);
        friend ostream& operator<<(ostream& _cout, const Date& d)
        {
            _cout << d.m_year << "-" << d.m_month << "-" << d.m_day;
            return _cout; 
        }
    private:
        int m_year;
        int m_month;
        int m_day;
};

Date::Date(int year, int month, int day)
    : m_year(year)
    , m_month(month)
    , m_day(day)
{

}

template<class T>
void Print(const vector<T>& v)
{
    for (auto& e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

void Test(void)
{
    vector<int> v1;
    vector<int> v2(10, 5);
    vector<int> v3(10);
    vector<Date> v4(10);

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v5(array, array + sizeof(array) / sizeof(int));

    vector<int> v6{1, 2, 3, 4, 5, 6};
    Print(v2);
    Print(v3);
    Print(v4);
    Print(v5);
    Print(v6);
}

void Test2()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = v.rbegin(); it != v.rend() ; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    Test();
    Test2();
    return 0;
}
