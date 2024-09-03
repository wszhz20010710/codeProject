#include <iostream>
#include <string>
using namespace std;

// 成员变量和成员函数分开存储
class Person
{
    int m_A;// 非静态成员变量属于类的对象上
    static int m_B;// 静态成员变量不属于类的对象上

    void func() // 非静态成员函数不属于类的对象上
    {

    }

    static void func2() // 静态成员函数不属于类的对象上
    {

    }
};
int Person::m_B = 100;

void test01()
{
    Person p;
    cout << "size of p = " << sizeof(p) << endl;
}

void test02()
{
    Person p;
    cout << "size of p = " << sizeof(p) << endl;
}

int main()
{
    test02();

    system("pause");
    return 0;
}