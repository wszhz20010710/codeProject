#include <iostream>
#include <string>
using namespace std;

// 类对象作为类成员
class Phone
{
public:
    Phone(string Pbrand)
    {
        cout << "Phone的构造函数调用" << endl;
        m_Pbrand = Pbrand;
    }

    ~Phone()
    {
        cout << "Phone析构函数调用" << endl;
    }

    string m_Pbrand;
};

class Person
{
public:
    Person(string name, string Pbrand): m_name(name), m_phone(Pbrand)
    {
        cout << "Person的构造函数调用" << endl;
    }

    ~Person()
    {
        cout << "Person析构函数的调用" << endl;
    }
    
    string m_name;
    Phone m_phone;
};

void test01()
{
    Person p("zhz", "apple");
    cout << "name: " << p.m_name << endl;
    cout << "phone: " << p.m_phone.m_Pbrand << endl;
}

int main()
{
    test01();

    system("pause");
    return 0;
}