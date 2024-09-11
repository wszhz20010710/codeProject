#include <iostream>
#include <string>
using namespace std;

// 菱形继承
// 动物类
class Animal
{
public:
    int m_Age;

};

// 利用虚继承可以解决菱形继承的问题
// 羊类
class Sheep : virtual public Animal // Animal变为虚基类
{

};

// 驼类
class Camel : virtual public Animal
{

};

// 羊驼类
class Alpaca : public Sheep, public Camel
{

};

void test01()
{
    Alpaca alp;
    alp.Sheep::m_Age = 18;
    alp.Camel::m_Age = 28;
    
    // 当出现菱形继承时，两个父类拥有相同的数据，需要加一个作用域区分
    cout << "alp.Sheep::m_Age = " << alp.Sheep::m_Age << endl;
    cout << "alp.Camel::m_Age = " << alp.Camel::m_Age << endl;
    cout << "alp.m_Age = " << alp.m_Age << endl;
}

int main(){

    test01();

    system("pause");
    return 0;
}
