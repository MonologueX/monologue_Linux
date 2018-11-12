/***********************************
 * 文件名称:main.cpp 
 * 文件描::类和对象练习 
 * 编译环境:Linux
 * 作者相关:心文花雨
***********************************/

#include <iostream>
#include <string.h>
using namespace std;

//class Student 
//{
//public:
//    char m_name[20];
//    char m_gender[3];
//    int m_age;
//    
//    void Set(char *name, char *gender, int age)
//    {
//        strcpy(m_name, name);
//        strcpy(m_gender, gender);
//        m_age = age;
//    }
//
//    void Print()
//    {
//        cout << m_name << " " << m_gender << " " << m_age << endl;
//    }
//};
//
//int main()
//{
//    Student s1,s2,s3;
//
//    s1.Set("张三", "男", 15);
//    s2.Set("李四", "男", 19);
//    s3.Set("小花", "女", 18);
//
//    s1.Print();
//    s2.Print();
//    s3.Print();
//    return 0;
//}
class A1
{
    public:
        void Set(int a)
        {
            m_a = a;
        }

    private:
        int m_a;
};


class A2
{
    public:
        void Test_A2()
        {
            cout << "void Test_A2()" << endl;
        }
};

class A3
{};

int main()
{
    cout << sizeof(A1) << endl;    
    cout << sizeof(A2) << endl;    
    cout << sizeof(A3) << endl;    
    return 0;
}
