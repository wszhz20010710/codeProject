#include <iostream>
using namespace std;

class Person
{
    // 权限
    // 公共权限public：类内外都可访问
public:
    string m_name;
    // 保护权限protected：类内可以访问，类外不可以
protected:
    string m_car;
    // 私有权限private：类内可以访问，类外不可以
private:
    int m_pwd;

public:
    void func()
    {
        m_name = "zhz";
        m_car = "bmw";
        m_pwd = 114514;
    }
};

int main()
{
    Person p1;

    p1.m_name = "cjh";
    // p1.m_car = "benz"; // 保护权限的内容在类外不可访问
    // p1.m_pwd = 0; // 隐私权限内容在类外不可访问

    system("pause");
    return 0;
}