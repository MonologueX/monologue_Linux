class Date
{
public:
	int GetMonthDay(int year, int month);
	void Set(int year, int month, int day);
	void Print(int size);

private:
	int m_year;
	int m_month;
	int m_day;
};