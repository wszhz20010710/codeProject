#include <iostream>
#include <string>
using namespace std;

// 继承方式

// father
class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;

};
// 公共继承
class Son1 : public Base1
{
public:
    void func()
    {
        m_A = 10;
        m_B = 20;
        // m_C = 30; m_C不可访问
    }

};

void test01()
{
    Son1 s1;
    s1.m_A = 100;
    // s1.m_B = 200; 保护权限，类外不可访问
}

// 保护继承
class Son2 : protected Base1
{
public:
    void func()
    {
        m_A = 100;
        m_B = 200;
        // m_C = 300; 父类中的私有权限变为不可访问
    }

};

void test02()
{
    Son2 s2;
    // 保护权限，类外不可访问
    // s2.m_A = 100;
    // s2.m_B = 200;

}
// 私有继承
class Son3 : private Base1
{
public:
    void func()
    {
        m_A = 100;
        m_B = 100;
        // m_C = 100; 父类中的private变为不可访问
    }
};

void test03()
{
    Son3 s3;
    // 私有
    // s3.m_A = 100;
    // s3.m_B = 200;

    // 不可访问
    // s3.m_C = 300;

}

class GrandSon3 : public Son3
{
public:
    void func()
    {
        // m_A = 100; 不可访问
    }
};