#include <iostream>
using namespace std;

void ReferenceTest(){	int a = 1;	int &ra = a;	cout << a << endl;	cout << ra << endl;	cout << &a << endl;	cout << &ra << endl;}int main()
{
	ReferenceTest();
	getchar();
	return 0;
}//class Date
//{
//public:
//	Date(int year = 2018, int month = 11, int day = 23);
//	Date(const Date& d);
//	bool operator==(const Date& d1);
//private:
//	int m_year;
//	int m_month;
//	int m_day;
//};
//
//Date::Date(int year, int month, int day)
//{
//	m_year = year;
//	m_month = month;
//	m_day = day;
//}
//
//class String
//{
//public:
//	String(const char* str = "word");
//	~String();
//private:
//	char* _str;
//};
//
//String::String(const char* str)
//{
//	_str = (char*)malloc(strlen(str) + 1);
//	strcpy(_str, str);
//}
//
//String::~String()
//{
//	cout << "~String()" << endl;
//	free(_str);
//}
//
//Date::Date(const Date& d)
//{
//	m_year = d.m_year;
//	m_month = d.m_month;
//	m_day = d.m_day;
//}
//
//bool Date::operator==(const Date& d)
//{
//	return  m_year == d.m_year && 
//		   m_month == d.m_month && //		     m_day == d.m_day;
//}
//
//void Test()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//}
////void FunTest(int a = 1, int b = 2, int c = 3)//{//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;//}////extern "C" int Add(int left, int right)//{//	return left + right;//}