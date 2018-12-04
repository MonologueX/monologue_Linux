/***********************************
 * 文件名称: string.cpp
 * 文件描述: 模拟String 类
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <iostream>
using namespace std;
#include <assert.h>
#include <string.h>


/*
 * 类名: String 
 * 备注: 传统的写法
*/
#if 0
class String
{
    public:
        String(const char* str = "");
        ~String();
        String(const String& s);
        String& operator=(const String&s);
    private:
        char *m_str;
};

String::String(const char* str)
{
    //assert(str);
    if (nullptr == str)
    {
        str = "";
    }

    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);

//    if (nullptr == str)
//    {
//        m_str = new char[1];
//        *m_str = '\0';
//    }
//    else 
//    {
//        m_str = new char[strlen(str) + 1];
//        strcpy(m_str, str);
//    }
}

String::~String()
{
    if (m_str)
    {
        delete[] m_str;
        m_str = nullptr;
    }
}

String::String(const String& s)
    :m_str(new char[strlen(s.m_str) + 1])
{
   strcpy(m_str, s.m_str);
}

String& String::operator=(const String&s)
{
    if (this != &s)
    {
        /*
        delete[] m_str;
        m_str = new char[strlen(s.m_str) + 1];
        strcpy(m_str, s.m_str);
        */
        char* pStr = new char[strlen(s.m_str) + 1];
        strcpy(pStr, s.m_str);
        delete[] m_str;
        m_str = pStr;
    }
    return *this;
}

void Test()
{
    String s1("hello");
    String s2(s1);
    String s3;
    s3 = s1;
}

int main()
{
    Test();
    return 0;
}
#endif


/*
 * 类名：String  
 * 备注：现代写法,代码比较简洁 
*/
#if 0
class String
{
    public:
        String(const char* str = "");
        ~String();
        String(const String& s);
        String& operator=(const String&s);
        void Print();
    private:
        char *m_str;
};

String::String(const char* str)
{
    if (nullptr == str)
    {
        str = "";
    }
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
}

String::~String()
{
    if (m_str)
    {
        delete[] m_str;
        m_str = nullptr;
    }
}

String::String(const String& s)
    :m_str(nullptr)
{
    String strTemp(s.m_str);
    swap(m_str, strTemp.m_str);
}

//String& String::operator=(String s)
//{
//    swap(m_str, s.m_str);
//    return *this;
//}

String& String::operator=(const String&s)
{
    if (this != &s)
    {
        String strTemp(s);
        swap(m_str, strTemp.m_str);
    }
    return *this;
}

void String::Print()
{
    cout << m_str << endl;
}

void Test()
{
    String s1("hello");
    s1.Print();
    String s2(s1);
    s2.Print();
    String s3;
    s3 = s2;
    s3.Print();
}

int main()
{
    Test();
    return 0;
}
#endif 

class String
{
    public:
        String(const char* str = "");
        ~String();
        String(String& s);
        String& operator=(const String&s);
        void Print();
    private:
        char *m_str;
        int *m_pCount;
        static int m_count;
};

String::String(const char* str)
{
    if (nullptr == str)
    {
        str = "";
    }
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
    m_count = 1;
}

String::~String()
{
    if (0 == --m_count && m_str)
    {
        delete[] m_str;
        m_str = nullptr;
    }
    cout << m_count << endl;
}

String::String(String& s)
    :m_str(s.m_str)
{
    ++m_count;
}

//String& String::operator=(const String&s)
//{
//    if (this != &s)
//    {
//        String strTemp(s);
//        swap(m_str, strTemp.m_str);
//    }
//    return *this;
//}

void String::Print()
{
    cout << m_str << endl;
    cout << m_count << endl;
}

int String::m_count = 0;
void Test()
{
    String s1("string");
    s1.Print();
    String s2(s1);
    s2.Print();
}

int main()
{
    Test();
    return 0;
}
