#include <iostream>
#include <string>
using namespace std;

// 继承同名静态成员的处理方式
class Base
{
public:
    static int m_A;

    static void func()
    {
        cout << "Base-static void func()" << endl;
    }

    static void func(int a)
    {
        cout << "Base-static void func(int a)" << endl;
    }

};
int Base::m_A = 100;

class Son : public Base
{
public:
    static int m_A;

    static void func()
    {
        cout << "Son-static void func()" << endl;
    }

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

// 同名静态函数属性
void test02()
{
    // 1.通过对象访问数据
    Son s;
    s.func();
    s.Base::func();

    // 2.通过类名访问数据
    Son::func();
    Son::Base::func();

    Son::Base::func(100);
}

int main(){

    //test01();
    test02();


    system("pause");
    return 0;
}