#include "Date.h"
#include <iostream>
using  namespace std;

int Date::GetMonthDay(int year, int month)
{
	static int MonthDay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && (year % 4 == 0 && year % 100 != 0)
		|| (year % 400 == 0))
		return 29;
	return MonthDay[month];
}

void Date::Set(int year, int month, int day)
{
	if (year > 1900 && month <= 12 && month > 0
		&& day > 0 && day <= GetMonthDay(year, month))
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else
	{
		cout << year << "-" << month << "-" << day;
		cout << "是非法日期" << endl;
	}
}

void Date::Print(int size)
{
	int flag = 0;
	printf("七\t一\t二\t三\t四\t五\t六\t\n");
	//printf("%d年 %d月\n", m_year, m_month);
	for (int i = 1; i < size; ++i)
	{
		if (0 == flag % 7 && flag > 0)
			printf("\n");
		if (i < m_day)
		{
			printf(" \t");
		}

		else
		{
			if (i < 10)
				printf("0");
			printf("%d\t", m_day++);
		}
		flag++;
	}
}

int main()
{
	Date d1;
	d1.Set(2018, 11, 16);
	int size = d1.GetMonthDay(2018, 11);
	d1.Print(31);
	system("pause");
	return 0;
}