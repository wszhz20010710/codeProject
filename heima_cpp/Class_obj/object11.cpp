#include <iostream>
#include <string>
using namespace std;

// this指针

class Person
{
public:
    Person(int age)
    {
        // this指针指向被调用成员函数所属的对象
        this->age = age;
    }

    Person& PersonAddAge(Person &p)
    {
        this->age += p.age;
        // 此处*this指向对象本体
        return *this;
    }

    int age;
};

// 1.解决名称冲突
void test01()
{
    Person p1(18);
    cout << "age of p1 = " << p1.age << endl;
}

// 2.在类的非静态成员函数返回对象本身
void test02()
{
    Person p1(10);
    Person p2(10);

    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout << "age of p2 = " << p2.age << endl;
}

int main(){

    test02();

    system("pause");
    return 0;
}