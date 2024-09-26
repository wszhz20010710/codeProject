#include <iostream>
#include <string>
using namespace std;

// 类模板对象做函数参数
template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout << "name: " << this->m_Name << endl;
        cout << "age: " << this->m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};

// 1.指定传入的类型：直接显示对象的数据类型
void printPerson(Person<string, int>&p)
{
    p.showPerson();
}
void test01()
{
    Person<string, int>p("孙悟空", 100);
    printPerson(p);
}
// 2.参数模板化：将对象中的参数变为模板进行传递
template<class T1, class T2>
void printPerson2(Person<T1, T2>&p)
{
    p.showPerson();
    cout << "type of T1: " << typeid(T1).name() << endl;
    cout << "type of T2: " << typeid(T2).name() << endl;
}
void test02()
{
    Person<string, int>p("猪八戒", 90);
    printPerson2(p);

}

// 3.整个类模板化：将这个类型进行模板化传递
template<class T>
void printPerson3(T &p)
{
    p.showPerson();
    cout << "type of T: " << typeid(T).name() << endl;
}
void test03()
{
    Person<string, int>p("唐僧", 30);
    printPerson3(p);
}

int main()
{
    test03();

    system("pause");
    return 0;
}