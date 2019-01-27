/***********************************
 * 文件名称: main.cpp
 * 文件描述: 
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

#include <iostream>
using namespace std;

class Base
{
    public:
        void SetBase(int pri, int pro, int pub);
        void Print();
    private:
        int m_pri;
    public:
        int m_pro;
    protected:
        int m_pub;
};

class Derivet : Base
{};

int main()
{
    
    return 0;
}






