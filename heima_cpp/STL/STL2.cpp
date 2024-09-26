#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// vector存放自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;

    }

    string m_Name;
    int m_Age;
};

void test01()
{
    vector<Person> v;

    Person p1("A", 10);
    Person p2("B", 20);
    Person p3("C", 30);
    Person p4("D", 40);
    Person p5("E", 50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 遍历数据
    vector<Person>::iterator itBegin = v.begin();
    vector<Person>::iterator itEnd = v.end();
    for (vector<Person>::iterator it = itBegin; it != itEnd; it++)
    {
        cout << "name: " << it->m_Name << "   " 
            << "age: " << it->m_Age << " test01" << endl;
    }
    
}

// vector存放自定义数据类型 指针
void test02()
{
    vector<Person*> v;

    Person p1("A", 10);
    Person p2("B", 20);
    Person p3("C", 30);
    Person p4("D", 40);
    Person p5("E", 50);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5); 

    // 遍历
    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    { 
        cout << "name: " << (*it)->m_Name << "   " << "age: "
            << (*it)->m_Age << " test02 " << endl;
    }
}
int main()
{

    test01();
    test02();
    system("pause");
    return 0;
}