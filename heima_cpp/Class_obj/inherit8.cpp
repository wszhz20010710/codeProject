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

// 羊类
class Sheep : public Animal
{

};

// 驼类
class Camel : public Animal
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

    cout << "alp.Sheep::m_Age = " << alp.Sheep::m_Age << endl;
    cout << "aalp.Camel::m_Age = " << alp.Camel::m_Age << endl;
}

int main(){

    test01();

    system("pause");
    return 0;
}
