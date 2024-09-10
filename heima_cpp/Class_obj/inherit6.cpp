#include <iostream>
#include <string>
using namespace std;

// 继承同名静态成员的处理方式
class Base
{
public:
    static int m_A;

};
int Base::m_A = 100;

class Son : public Base
{
public:
    static int m_A;
};
int Son::m_A = 200;

// 同名静态成员属性
void test01()
{
    // 1.通过对象访问数据
    cout << "通过对象的访问：" << endl;
    Son s;
    cout << "Son下的m_A = " << s.m_A << endl;
    cout << "Base下的m_A = " << s.Base::m_A << endl;

    // 2.通过类名访问数据
    cout << "通过类名的访问：" << endl;
    cout << "Son下的m_A = " << Son::m_A << endl;
    cout << "Base下的m_A = " << Base::m_A << endl;
    cout << "Base下的m_A = " << Son::Base::m_A << endl;

}

int main(){

    test01();

    system("pause");
    return 0;
}