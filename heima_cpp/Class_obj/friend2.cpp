#include <iostream>
#include <string>
using namespace std;

// 类函数作友元
class Building
{
    friend class GoodGay;
public:
    Building();
    string m_Sittingroom;

private:
    string m_Bedroom;
};

class GoodGay
{
public:
    GoodGay();
    void Visit()    // 参观函数，访问Building类中的属性
    { 
        cout << "GoodGay类正在访问：" << building->m_Sittingroom << endl;
        cout << "GoodGay类正在访问：" << building->m_Bedroom << endl;
    }
    Building * building;
};

// 类外写成员函数
Building::Building()
{
    m_Sittingroom = "客厅";
    m_Bedroom = "卧室";
}

GoodGay::GoodGay()
{
    // 创建一个building对象
    building = new Building;
}

void test01()
{

    GoodGay gg;
    gg.Visit();
}

int main(){
    
    test01();
    system("pause");
    return 0;
}