#include <iostream>
#include <string>
using namespace std;

// 类模板的语法
template<class NameType, class AgeType>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

    void showPerson()
    {
        cout << "name: " << this->m_Name << endl;
        cout << "name: " << this->m_Age << endl; 
    }
    NameType m_Name;
    AgeType m_Age;
};

void test01()
{
    Person<string, int> p1("tom", 14);
    Person<string, int> p2("jack", 18);
    p1.showPerson();
    p2.showPerson();
}

int main()
{
    test01();

    system("pause");
    return 0;
}