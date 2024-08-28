#include <iostream>
#include <string>
using namespace std;

// 成员属性设置为私有
class Person
{
public:
    // 设置姓名
    void set_name(string name)
    {
        m_Name = name;
    }
    // 获取姓名
    string get_name()
    {
        return m_Name;
    }
    // 获取年龄
    int get_age()
    {
        return m_Age;
    }
    // 设置年龄0-150
    void set_age(int age)
    {
        if (age < 0 || age > 150)
        {
            cout << "年龄超出范围！" << endl;
            return;
        }
        m_Age = age;
    }
    // 设置idol
    void set_idol(string idol)
    {
        m_Idol = idol;
    }
private:
    string m_Name; // 姓名，可读可写
    int m_Age = 18; // 年龄，只读
    string m_Idol; // 偶像，只写
};

int main()
{
    Person p;
    p.set_name("zhz");
    cout << "姓名：" << p.get_name() << endl;

    cout << "年龄：" << p.get_age() << endl;

    p.set_idol("cxk");
    // cout << "偶像：" << p.m_Idol

    system("pause");
    return 0;
}