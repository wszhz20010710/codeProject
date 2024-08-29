#include <iostream>
using namespace std;

// 构造函数的分类和调用

// 分类
// 按参数：有参构造和无参构造
// 按类型：普通构造和拷贝构造
class Person
{
public:
    Person() // 无参构造，默认构造
    {
        cout << "Person无参构造函数的调用" << endl;
    }

    Person(int a) // 有参构造
    {
        age = a;
        cout << "Person有参构造函数的调用" << endl;
    }

    Person(const Person &p) // 拷贝构造
    {
        // 将传入的人身上所有属性拷贝到我身上
        age = p.age;
        cout << "Person拷贝构造函数的调用" << endl;
    }

    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }

    int age;
};

// 调用
void test01()
{
    // 1.括号法
    // Person p1; // 默认构造的调用
    // Person p2(10); // 有参构造的调用
    // Person p3(p2);// 拷贝构造函数的调用

    // cout << "p2的年龄为:" << p2.age << endl;
    // cout << "p3的年龄为:" << p3.age << endl;

    // 2.显示法
    Person p1;  // 默认构造的调用
    Person p2 = Person(10); // 有参构造的调用
    Person p3 = Person(p2);// 拷贝构造函数的调用

    // Person(10); // 创建了匿名对象，当前行结束后系统回收匿名对象
    // cout << "aaaaa" << endl;

    // 3.隐式转换法
    Person p4 = 10;// 有参构造的调用,相当于Person p4 = Person(10)
    Person p5 = p4;// 拷贝构造函数的调用
}

int main()
{
    test01();

    system("pause");
    return 0;
}