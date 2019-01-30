/***********************************
 * 文件名称: string.cpp
 * 文件描述: 复习 String
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <iostream>
#include <string>
using namespace std;

void Test()
{
    string s1("Hello");
    string s2 = "Linux";
    string s3(s1);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    char str1[] = "string";
    char str2[] = "厉害";
    cout << sizeof(str1) << endl;
    cout << sizeof(str2) << endl;

    string file("file.cpp");
    string suffix(file, 4, 4);
    cout << suffix << endl;

    string path("F:\C++", 3);
    cout << path << endl;
}

int StrToInt1(string str)
{
    //for (size_t i = 0; i < str.size(); ++i)
    //{
    //    cout << str[i] << " ";
    //    cout << str.operator[](i) << " ";
    //}
    //cout << endl;
    
    //int value = 0;
    //for (size_t i = 0; i < str.size(); ++i)
    //{
    //    value *= 10;
    //    value += str[i] - '0';
    //}
    //return value;
    
    int value = 0;
    string::iterator it  = str.begin();
    while (it != str.end())
    {
        value *= 10;
        value += (*it - '0');
        ++it;
    }
    return value;
}

void Test2()
{
    StrToInt1("12345");
}

int main()
{
    Test2();
    return 0;
}

