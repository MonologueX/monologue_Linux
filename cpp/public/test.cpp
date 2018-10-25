/////////////////////////////// 
//  文件名称:类和对象 
//  文件描述:1
//  编译环境:Linux
//  作者相关:心文花雨 

#include<iostream>
#include <unistd.h>
#include <string.h>
using namespace std;

///////////////////////////////
// 函数
class Student
{
  void SetStudentInfo(char* name, char* sex,  int age)
  {
    strcpy(_name, name);
    strcpy(_sex, sex);
    _age = age;
  }
  char _name[20];
  char _sex;
  int _age;
};


///////////////////////////////
// 主函数
int main()
{
  Student s; 
  return 0;
}
