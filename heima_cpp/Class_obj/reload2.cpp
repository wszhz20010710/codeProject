#include <iostream>
#include <string>
using namespace std;

// 左移运算符<<的重载
class Person
{
    friend ostream & operator<<(ostream &cout, Person &p);
private:
    // 一般不使用成员函数来重载<<运算符
    // void operator<<()
    // {

    // }
    int m_A = 10;
    int m_B = 10;

};

// 全局函数重载<< 
ostream & operator<<(ostream &cout, Person &p)
{
    cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
    return cout;
}

void test01()
{
    Person p;
    // p.m_A = 10;
    // p.m_B = 10;

    // cout << p.m_A << endl;
    cout << p << " hello world!" << endl;
}

int main(){

    test01();
    system("pause");
    return 0;
}