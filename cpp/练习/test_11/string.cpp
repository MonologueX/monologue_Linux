/***********************************
 * 文件名称: main.cpp
 * 文件描述: Sting 类
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
#include <iostream>
using namespace std;

#include <string>
void TestString1()
{
	string s1;
	string s2("string");
	string s3(15, 'a');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}

void TestStringResize()
{
	string s("string");
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;

	s.resize(20, '$');
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;

	s.resize(24, '@');
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;

	s.resize(10, '$');
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
}

// 容量变
void TestStringReserve1()
{
	string s;
	s.reserve(30);
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;

	s.resize(20, '$');
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;

	s.resize(24, '@');
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;

	s.resize(10);
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;

	s.reserve(10);
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;

	s.clear();
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
}

// 容量不变
void TestStringReserve2()
{
	string s("string");
	s.resize(20, '$');
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;

	s.reserve(20);
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;

	s.reserve(15);
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	
	s.reserve(10);
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
}

int main()
{
	TestStringReserve1();
    cout << endl;
	TestStringReserve2();
	return 0;
}
