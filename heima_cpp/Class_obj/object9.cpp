#include <iostream>
#include <string>
using namespace std;

// 静态成员函数特点
// 1.所有对象共享同一个函数
// 2.静态成员函数只能访问静态成员变量

class Person
{
public:
    static void func()
    {
        m_A = 100;// 静态成员函数可以访问静态成员变量
        //m_B = 200;// 静态成员函数不可以访问 非静态成员变量
        // 原因是无法区分是哪个对象的m_B属性
        cout << "static void func的调用" << endl;
    }

    static int m_A;// 静态成员变量
    int m_B;// 非静态成员变量

private:
    static void func2()
    {
        cout << "static void func2的调用" << endl;
    }
};

int Person::m_A = 0;

void test01()
{
    // 1.通过对象
    Person p;
    p.func();
    // 2.通过类名
    Person::func();

}

int main()
{
    test01();

    system("pause");
    return 0;
}