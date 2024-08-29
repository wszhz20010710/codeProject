#include <iostream>
using namespace std;

// 对象的初始化和清理

class Person
{
public:
    // 构造函数：类名+()+{}
    // 1.没有返回值，不写void
    // 2.函数名与类名相同
    // 3.可以有参数，可以发生重载
    // 4.程序在调用对象时会自动调用，且只会调用一次
    Person()
    {
        cout << "Person构造函数的调用" << endl;
    }

    // 析构函数： ~类名(){}
    // 1.没有返回值，不写void
    // 2.函数名与类名相同，前面加上~
    // 3.不可以有参数，不可以发生重载
    // 4.程序在对象销毁前会自动调用，且只会调用一次
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }

};

// 构造函数和析构函数都是必须有的实现，
// 如果自己不提供，编译器提供的构造函数和析构函数是空实现
void test01()
{
    Person p; // 栈上的数据，test01执行完以后，释放这个对象
}


int main()
{
    //test01();
    Person p;

    system("pause");
    return 0;
}