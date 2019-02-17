#include <iostream>
#include <string>

class Person
{
    public:
        virtual void BuyTickets()
        {
            std::cout << "买票--全价" << std::endl;
        }
    protected:
        std::string m_name;
};

class Student : public Person
{
    public:
        virtual void BuyTickets()
        {
            std::cout << "买票--半价" << std::endl;
        }
    protected:
        int m_num;
};

void Fun(Person& p)
{
    p.BuyTickets();
}

void Test1()
{
    Person p;
    Student s;
    Fun(p);
    Fun(s);
}

class Base
{
    public:
        virtual void TestFun1()
        {
            std::cout << "[Base]:Fun1()" << std::endl;
        }
        virtual void TestFun2()
        {
            std::cout << "[Base]:Fun2()" << std::endl;
        }
        void TestFun3()
        {
            std::cout << "[Base]:Fun3()" << std::endl;
        }
        virtual void TestFun4()
        {
            std::cout << "[Base]:Fun4()" << std::endl;
        }
        //virtual int TestFun5()
        //{
        //    std::cout << "[Base]:Fun5()" << std::endl;
        //    return 0;
        //}
    protected:
        int m_b;
};

class Derived : public Base
{
    public:
        // 构成重写
        virtual void TestFun1()
        {
            std::cout << "[Derived]:Fun1()" << std::endl;
        }
        // virtual 可加可不加
        void TestFun2()
        {
            std::cout << "[Derived]:Fun2()" << std::endl;
        }
        // 没有构成重写
        virtual void TestFun3()
        {
            std::cout << "[Derived]:Fun3()" << std::endl;
        }
        // 没有构成重写
        virtual void TestFun4(int a = 1)
        {
            std::cout << "[Derived]:Fun4()" << std::endl;
        }
        // 报错
        //virtual void TestFun5()
        //{
        //    std::cout << "[Derived]:Fun5()" << std::endl;
        //}
    protected:
        int m_d;
};

void Test(Base& b)
{
    b.TestFun1();
    b.TestFun2();
    b.TestFun3();
    b.TestFun4();
    //b.TestFun5();
}

int main()
{
    Base b;
    Derived d;
    Test(b);
    Test(d);
    return 0;
}
