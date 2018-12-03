#include <iostream>
using namespace std;
#include <assert.h>
#include <string.h>

class String
{
    public:
        String(const char* str = "");
        ~String();
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

int main()
{
    
    return 0;
}
