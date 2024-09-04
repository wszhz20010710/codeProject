#include <iostream>
#include <string>
using namespace std;

// const修饰成员函数
// 常函数：
class Person
{
public:
    Person()
    {
        
    }
    // 1.成员函数后加const称为常函数
    // this指针的实质是一个指针常量，不可修改指针指向
    // Person * const this
    // 实质上是修饰this指针，让指针指向的值也不可以修改
    void showPerson() const
    {
        // 2.常函数内不可修改成员属性
        //this->m_A = 100;
        this->m_B = 1000;            
        cout << "m_B = " << m_B << endl;
    }
    int m_A;
    // 3.成员属性声明时加关键字mutable后，在常函数中可修改
    mutable int m_B;

    void func()
    {

    }
};

void test01()
{
    Person p;
    p.showPerson();

}

// 常对象：
// 1.声明对象前加const称为常对象
// 2.常对象只能调用常函数
void test02()
{
    const Person p;
    p.showPerson();

}


int main(){

    test02();

    system("pause");
    return 0;
}