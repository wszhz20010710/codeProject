#include <iostream>
#include <string>
using namespace std;

// 类模板与继承

template<class T>
class Base
{
    T m;
};
// 1.子类继承的是父类的一个类模板时，子类在声明时需要指出父类中T的类型
// wrong 需要知道父类中T的类型
// class Son : public Base
// {

// };
class Son:public Base<int>
{

};
void test01()
{
    Son s1;
}
//3.如果想灵活指定出父类的T类型，子类也需要变成类模板
template<class T1, class T2>
class Son2:public Base<T2>
{
public:
    Son2()
    {
        cout << "type of T1: " << typeid(T1).name() << endl;
        cout << "type of T2: " << typeid(T2).name() << endl;
    }
    T1 obj;
};

void test02()
{
    Son2<int, char>s2;
}

int main()
{
    test02();

    system("pause");
    return 0;
}