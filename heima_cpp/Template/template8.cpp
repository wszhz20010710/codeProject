#include <iostream>
#include <string>
using namespace std;

// 类模板与函数模板的区别
template<class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout << "Name: " << this->m_Name << endl;
        cout << "Age: " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};
// 1.类模板没有自动类型推导的使用方式
void test01()
{
    //Person p("sunwukong", 1000);
    Person<string, int>p("孙悟空" , 1000);
    p.showPerson();
}
// 2.类模板在函数参数列表中可以有默认参数
void test02()
{
    Person<string>p("猪八戒", 999);
    p.showPerson();

}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}