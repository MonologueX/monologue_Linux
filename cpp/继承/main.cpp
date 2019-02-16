#include <iostream>
using namespace std;

class Person
{
    public:
        Person(const string& name = "test")
            :m_name(name)
        {}
        void Test()
        {
            cout << m_name << endl;
        }
    private:
        string m_name;
    protected:
};

class Student : public Person
{
    public:
    private:
        int m_num;
    protected:
};

void Test()
{
    Student s;
    cout << "size:" << sizeof(s) << endl;
    s.Test();
}

int main()
{
    Test();
    return 0;
}
