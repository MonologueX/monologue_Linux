#include <iostream>
using namespace std;

class Date
{
public:
	void Set(int year, int month, int day);
	void Print(void) const;
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	Date& operator=(const Date& d);
	Date& operator++();
	Date& operator++(int);
private:
	int m_year;
	int m_month;
	int m_day;
};

void Date::Set(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}

Date::Date(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}

void Date::Print(void) const
{
	cout << m_month << "-" << m_month << "-" << m_day << endl;
}

Date::Date(const Date& d)
{
	m_year = d.m_year;
	m_month = d.m_month;
	m_day = d.m_day;
}

Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		m_year = d.m_year;
		m_month = d.m_month;
		m_day = d.m_day;
	}
}

Date& Date::operator++()
{
	m_day += 1;
	return *this;
}

Date& Date::operator++(int)
{
	Date temp(*this);
	m_day += 1;
	return temp;
}
void Test()
{
	Date d1;
	Date d2(2018, 1, 26);
	// 这里d1调用的编译器生成operator=完成拷贝，d2和d1的值也是一样的。
	d1 = d2;
}

int main()
{

	return 0;
}