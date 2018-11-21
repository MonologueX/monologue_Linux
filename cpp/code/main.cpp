#include <iostream>
using namespace std;
#include <assert.h>

class Time
{
    public:
        void TimePrint();
        void TimeSet(int hour, int minutes, int second);
    private:
        int m_hour;
        int m_minutes;
        int m_second;
};

void Time::TimeSet(int hour, int minutes, int second)
{
    if (hour >= 0 && hour < 13 && 
        minutes >= 0 && minutes <= 60 && 
        second >= 0 &&second <= 60)
    {
        m_hour = hour;
        m_minutes = minutes;
        m_second = second;
    }
    else 
    {
        
    }
}

void Time::TimePrint()
{
    cout << m_hour << ":" << m_minutes << ":" << m_second << endl;
}

class Date
{
    public:
        Date(int year, int month, int day);
        void DatePrint();
        int GetDay(int year, int month);
    private:
        int m_year;
        int m_month;
        int m_day;
};

void Date::DatePrint()
{
    cout << m_year << "-" << m_month << "-" << m_day << endl;
}


int Date::GetDay(int year, int month)
{
    static int MonthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && 
        ((year%4 == 0 && year%100 != 0) || (year % 400 == 0)))
    }
    m_hour = hour;
    m_minutes = minutes;
    m_second = second;
}

void Time::TimePrint()
{
    cout << m_hour << ":" << m_minutes << ":" << m_second << endl;
}

class Date
{
    public:
        Date(int year, int month, int day);
        void DatePrint();
        int GetDay(int year, int month);
    private:
        int m_year;
        int m_month;
        int m_day;
};

void Date::DatePrint()
{
    cout << m_year << "-" << m_month << "-" << m_day << endl;
}


int Date::GetDay(int year, int month)
{
    static int MonthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && 
        ((year%4 == 0 && year%100 != 0) || (year % 400 == 0)))
    {
        return 29;
    }
    return MonthDay[month];
}

Date::Date(int year, int month, int day)
{
    if (year > 1900 &&
        month > 0 && month < 13 &&
        day > 0 && day <= GetDay(year, month))
    {
        m_year = year;
        m_month = month;
        m_day = day;
        DatePrint();
    }
    else 
    {
        cout << "非法日期" << endl;
        assert(false);
    }
}

void DateTest()
{
    Date d1(2018, 11, 28);
}

int main()
{
    DateTest();
    return 0;
}
