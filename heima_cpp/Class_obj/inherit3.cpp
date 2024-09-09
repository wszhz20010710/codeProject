#include <iostream>
#include <string>
using namespace std;

// 继承中的对象模型
class Base
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C; // 父类中的私有成员属性是被编译器隐藏了
};

class Son : public Base
{
public:
    int m_D;
};

void test01()
{
    cout << "size of son = " << sizeof(Son) << endl;
}

int main(){

    test01();

    system("pause");
    return 0;
}