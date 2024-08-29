#include <iostream>
using namespace std;

// 拷贝构造函数的调用时机
class Person
{
public:
    Person()
    {
        cout << "Person无参构造函数的调用" << endl;
    }

    Person(int age)
    {
        cout << "Person有参构造函数的调用" << endl;
        m_age = age;
    }

    Person(const Person &p)
    {
        cout << "Person拷贝构造函数的调用" << endl;
        m_age = p.m_age;
    }

    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
    int m_age;
};

// 1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person p1(20);
    Person p2(p1);

    cout << "p2的年龄为：" << p2.m_age << endl;
}
// 2.值传递的方式给函数参数传值
void dowork01(Person p)
{

}
void test02()
{
    Person p;
    dowork01(p);
}

// 3.以值方式返回局部对象
Person dowork02()
{
    Person p1;
    cout << (long long*)&p1 << endl;
    return p1;
}

void test03()
{
    Person p = dowork02();
    cout << (long long*)&p << endl;
}

int main()
{
    //test01();
    // test02();
    test03();

    system("pause");
    return 0;
}