#include <iostream>
#include <string>
using namespace std;

// 纯虚函数和抽象类
class Base
{
public:
    virtual void func() = 0;
    
};

class Son : public Base
{
public:
    virtual void func()
    {
        cout << "func函数的调用" << endl;
    }
};

void test01()
{
    // 抽象类无法实例化对象
    // Base b1;
    // new Base;

    Base * base = new Son;
    base->func();

}


int main(){

    test01();

    system("pause");
    return 0;
}