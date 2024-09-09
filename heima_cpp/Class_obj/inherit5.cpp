#include <iostream>
#include <string>
using namespace std;

// 继承同名成员处理方式
class Base
{
public:
    Base()
    {
        m_A = 100;
    }
    int m_A;
    
};

class Son : public Base
{
public:
    Son()
    {
        m_A = 200;
    }

    int m_A;
};

// 继承同名成员处理方式
void test01()
{
    Son s;
    // 访问子类同名成员，直接访问即可
    cout << "Son.m_A = " << s.m_A << endl;
    // 访问父类同名成员，需要加作用域
    cout << "Base.m_A = " << s.Base::m_A << endl;
}

// 继承同名成员函数处理方式
void test01()
{
    
}

int main(){

    test01();

    system("pause");
    return 0;
}