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

    void func()
    {
        cout << "Base下的函数func()调用" << endl;
    }

    void func(int a)
    {
        cout << "Base下的函数func(int a)调用" << endl;
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

    void func()
    {
        cout << "Son下的函数func()调用" << endl;
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
void test02()
{
    Son s;
    s.func();
    // 访问父类同名成员函数，需要加作用域
    s.Base::func();
    // 如果子类中出现和父类同名的成员函数，子类的同名成员函数会隐藏掉父类中所有的同名成员函数
    // 如果想访问需要加作用域
    s.Base::func(100);
    
}

int main(){

    //test01();
    test02();
    system("pause");
    return 0;
}