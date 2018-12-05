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

class String
{
    public:
        String(const char* str = "");
        ~String();
        String(const String& s);
        String& operator=(const String&s);
        char& operator[](size_t index);
        const char& operator[](size_t index)const;
        size_t Size()const;
        bool Empty()const;
        size_t Capacity()const;

    public:
        void Resize(size_t Newsize, char ch = char());
        void Reserve(size_t Newcapacity);
        void Clear();
        void Insert(size_t pos, char ch);
        void Erase(size_t pos, char ch);
        void Pushback(char ch);
        void Print();

        void operator+=(char ch);
        void operator+=(const String& str);
        void operator+=(char *str);


        bool operator>(const String& s);
        bool operator<(const String& s);
        bool operator==(const String& s);
        bool operator!=(const String& s);
        bool operator<=(const String& s);
        bool operator>=(const String& s);

        String Substr(size_t pos, size_t n);
    private:
        char *m_str;
        size_t m_size;
        size_t m_capacity;
};

String::String(const char* str)
    : m_size(strlen(str))
    , m_capacity(m_size + 1)
{
    if (nullptr == str)
    {
        str = "";
    }
    m_str = new char[m_capacity + 1];
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
    : m_str(new char[s.m_size + 1])
    , m_size(s.m_size)
    , m_capacity(s.m_size + 1)
{
    String strTemp(s.m_str);
    swap(m_str, strTemp.m_str);
}

String& String::operator=(const String&s)
{
    if (this != &s)
    {
        String strTemp(s);
        swap(m_str, strTemp.m_str);
    }
    return *this;
}

///////////////////////////////
// String 类接口
char& String::operator[](size_t index)
{
    assert(index < m_size);
    return m_str[index];
}

const char& String::operator[](size_t index)const 
{
    assert(index < m_size);
    return m_str[index];
}

size_t String::Size()const 
{
    return m_size;
}

bool String::Empty()const 
{
    return m_size == 0;
}

size_t String::Capacity()const 
{
    return m_capacity;
}

void String::Resize(size_t Newsize, char ch)
{
    if (Newsize <= m_size)
    {
        m_size = Newsize;
    }
    else 
    {
        if (Newsize > m_capacity)
        {
            char *pStr = new char[Newsize * 2];
            strcpy(pStr, m_str);

            delete[] m_str;
            m_str = pStr;
            m_capacity = Newsize * 2;
        }

        memset(m_str + m_size, ch, Newsize - m_size);
        m_size = Newsize;
        m_str[m_size] = '\0';
    }
}

void String::Reserve(size_t Newcapacity)
{
    if (Newcapacity > m_capacity)
    {
        char * pStr = new char[Newcapacity + 1];
        strcpy(pStr, m_str);

        delete[] m_str;
        m_str = pStr;
        m_capacity = Newcapacity;
    }
}


void String::Insert(size_t pos, char ch)
{

}

void String::Erase(size_t pos, char ch)
{

}

void String::Pushback(char ch)
{
    if (m_size == m_capacity)
    {
        Reserve(m_capacity * 2);
    }
        m_str[m_size++] = ch;
        m_str[m_size] = '\0';
}

void String::Clear()
{
    m_size = 0;
    m_str[0] = '\0';
}

void String::operator+=(char *str)
{
    int len = strlen(str);
    if (len > m_capacity - m_size)
    {
        Reserve(m_capacity * 2 + len);
    }
    strcat(m_str, str);
    m_size += len;
}

void String::Print()
{
    cout << m_str << endl;
}

void Test()
{
    String s("hello");
    cout << s.Size() << endl;
    cout << s.Capacity() << endl;
    s.Print();
    s += " word";
    cout << s.Size() << endl;
    cout << s.Capacity() << endl;
    s.Print();

    s.Resize(5);
    cout << s.Size() << endl;
    cout << s.Capacity() << endl;
    s.Print();

    s.Resize(10, '$');
    cout << s.Size() << endl;
    cout << s.Capacity() << endl;
    s.Print();

    s.Resize(30, '@');
    cout << s.Size() << endl;
    cout << s.Capacity() << endl;
    s.Print();

    s.Clear();
    cout << s.Size() << endl;
    cout << s.Capacity() << endl;
    s.Print();
}

int main()
{
    Test();
    return 0;
}
