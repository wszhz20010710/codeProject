#include <iostream>
using namespace std;

// 拷贝构造函数的调用规则

// 2.用户定义拷贝构造函数，coo不再提供其他构造函数

// 默认情况下，cpp会给一个类添加至少3个函数：
// 1.默认构造函数 无参，函数体为空
// 2.默认析构函数 无参，函数体为空
// 3.默认拷贝构造函数，对属性值进行拷贝

class Person
{
public:
    Person()
    {
        cout << "Person的默认构造函数调用" << endl;
    }

    Person(int age)
    {
        cout << "Person有参构造函数的调用" << endl;
        m_age = age;
    }

    // Person(const Person &p)
    // {
    //     cout << "Person拷贝构造函数的调用" << endl;
    //     m_age = p.m_age;
    // }

    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }

    int m_age;

};

// void test01()
// {
//     Person p;
//     p.m_age = 18;

//     Person p2(p);
//     cout << "p2的年龄为:" << p2.m_age << endl;
// }

void test02()
{
    // 1.用户定义有参构造函数，cpp不再提供默认无参构造，但会提供默认拷贝构造
    Person p(28);
    Person p2(p);
    cout << "p2的年龄为:" << p2.m_age << endl;
}

int main()
{
    test02();

    system("pause");
    return 0;
}