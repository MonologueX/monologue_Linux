#include <iostream>
using namespace std;

#include <malloc.h>
#include <unistd.h>

void* GetMemory(int size = 100)
{
  cout<<size<<endl;
  return malloc(size);
}

void TestFunc1(int a = 1, int b = 2, int c = 3)
{
  cout<<a<<" "<<b<<" "<<c<<endl;
}

// 从右往左依次给出
void TestFunc2(int a, int b = 2, int c = 3)
{
  cout<<a<<" "<<b<<" "<<c<<endl;
}

// 声明和定义不能同时出现 
void TestFunc3(int a);
void TestFunc3(int a = 10)
{
  cout<< a << endl;
}

void TeatFunc(int b = 10);
void TestFunc4(int b)
{
  cout<< b << endl;
}

///////////////////////////////////////////
// 错误
/////////////////////////////////////////// 
// void TestFunc(int a = 10);
// void TeatFunc(int a = 10)
// {
// 
// }


////////////////////////////////// 
// 函数重载
int Add(int left, int right)
{
  return left + right;
}

double Add(double left, double right)
{
  return left + right;
}

char Add(char left, char right)
{
  return left + right;
}

void Test()
{
  cout<< "Test 1"<<endl;
  GetMemory();
  GetMemory(10);
  cout<<endl;

  cout<< "Test 2"<<endl;
  TestFunc1(10, 20, 30);
  TestFunc1(10, 20);
  TestFunc1(10);
  TestFunc1();
  TestFunc2(10, 20, 30);
  TestFunc2(10, 20);
  TestFunc2(10);
  cout<<endl;

  cout<< "Test 3"<<endl;
  cout<<Add(1, 2)<<endl;
  cout<<Add(1.0, 2.1)<<endl;
  cout<<Add('1', '2')<<endl; 
  cout<<endl;
}

int main()
{
  Test();
  return 0;
}
