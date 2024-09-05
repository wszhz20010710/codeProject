#include <iostream>
#include <string>
using namespace std;

// 赋值运算符=的重载
class Person
{
public:
    Person(int age)
    {
        m_Age = new int(age);
    }

    ~Person()
    {
        if (m_Age != NULL)
        {
           delete m_Age;
           m_Age = NULL;
        }   
    }

    // 重载赋值运算符=
    Person& operator=(Person &p)
    {
        // 编译器提供浅拷贝 m_Age = p.m_Age
        // 应该先判断是否有属性在堆区，如果有，则需要先释放干净再深拷贝
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        // 深拷贝
        m_Age = new int(*p.m_Age);

        return *this;
    }

    int *m_Age;
};

void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1;

    cout << "age of p1 = " << *p1.m_Age << endl;
    cout << "age of p2 = " << *p2.m_Age << endl;
    cout << "age of p3 = " << *p3.m_Age << endl;
}

int main(){

    test01();
    // int a = 10;
    // int b = 20;
    // int c = 30;

    // c = b =a;

    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;
    // cout << "c = " << c << endl;
    system("pause");
    return 0;
}