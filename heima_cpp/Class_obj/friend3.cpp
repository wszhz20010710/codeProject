#include <iostream>
#include <string>
using namespace std;

// 成员函数作友元
class Building;
class GoodGay
{
public:
    GoodGay();
    void visit(); // 可以访问Building中的private成员
    void visit2(); // 不可以访问Building中的private成员
    Building * building;
};

class Building
{
    friend void GoodGay::visit();
public:
    Building();
    string m_Sittingroom;
private:
    string m_Bedroom;
};

Building::Building()
{
    m_Sittingroom = "客厅";
    m_Bedroom = "卧室";
}

GoodGay::GoodGay()
{
    building = new Building;
}

void GoodGay::visit()
{
    cout << "visit函数正在访问：" << building->m_Sittingroom << endl;
    cout << "visit函数正在访问：" << building->m_Bedroom << endl;
}
void GoodGay::visit2()
{
    cout << "visit2函数正在访问：" << building->m_Sittingroom << endl;

}

void test01()
{
    GoodGay gg;
    gg.visit();
    gg.visit2();
}

int main(){

    test01();
    
    system("pause");
    return 0;
}