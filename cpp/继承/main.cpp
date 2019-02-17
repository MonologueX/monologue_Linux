#include <iostream>
using namespace std;

//class Person
//{
//    public:
//        Person(const string& name = "test")
//            :m_name(name)
//        {}
//        void Test()
//        {
//            cout << m_name << endl;
//        }
//    private:
//        string m_name;
//    protected:
//};
//
//class Student : public Person
//{
//    public:
//    private:
//        int m_num;
//    protected:
//};
//
//void Test2()
//{
//    Person p;   // 父类
//    Student s;  // 子类
//    p = s;      // 没有类型转换发生
//
//    Person& r1 = s;
//
//    int i = 1;
//    const double& r2 = i;
//}
//
//void Test3()
//{
//    Person p;
//    Student s;
//    // s = p;
//    Person *p1;
//    // Student *s1 = p1;
//    Student *s2 = (Student *)p1;
//    Student& r = (Student &)p1;
//}
//
//void Testi1()
//{
//    Student s;
//    cout << "size:" << sizeof(s) << endl;
//    s.Test();
//}
//
//// 不可见
//class A
//{
//    private:
//        int m_a;
//    private:
//};
//
//class B : public A
//{
//    public:
//        void f()
//        {
//            //std::cout << m_a << std::endl;
//        }
//
//    private:
//        int m_b;
//};
//
//void Test()
//{
//    //B b;
//}

class Person
{
    public:
        Person(int num = 10)
            :m_num(num)
        {}
        void f()
        {
            cout << "Person" << endl;
        }
        int m_num;
    private:
};
class Student : public Person
{
    public:
        Student(int num = 20)
            :m_num(num)
        {}
        void f(int a)
        {
            cout << "Student" << endl;
        }
        int m_num;
    private:
};
void Test()
{
    Student s;
    s.f();
}

// 方法1
class A
{
    public:
    private:
        A()
        {}
};


int main()
{
    Test();
    return 0;
}
