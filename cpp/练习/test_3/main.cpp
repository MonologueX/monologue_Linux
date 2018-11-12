/***********************************
 * 文件名称:main.cpp 
 * 文件描述:类和对象练习 
 * 编译环境:Linux
 * 作者相关:心文花雨
***********************************/

#include <iostream>
#include <string.h>
using namespace std;

class Student 
{
public:
    char _name[20];
    char _gender[3];
    int _age;
    
    void Set(char *name, char *gender, int age)
    {
        strcpy(_name, name);
        strcpy(_gender, gender);
        _age = age;
    }

    void Print()
    {
        cout << _name << " " << _gender << " " << _age << endl;
    }
};

int main()
{
    Student s1,s2,s3;

    s1.Set("张三", "男", 15);
    s2.Set("李四", "男", 19);
    s3.Set("小花", "女", 18);

    s1.Print();
    s2.Print();
    s3.Print();
    return 0;
} 
