#include <iostream>
#include <string>
using namespace std;

// 全局函数作友元
class Building
{
    friend void goodGay(Building *building);
public:
    Building()
    {
        m_Sittingroom = "客厅";
        m_Bedroom = "卧室";
    }
    string m_Sittingroom;

private:
    string m_Bedroom;
};

// 全局函数
void goodGay(Building *building)
{
    cout << "全局函数正在访问：" << building->m_Sittingroom << endl;
    cout << "全局函数正在访问：" << building->m_Bedroom << endl;
}

void test01()
{
    Building building;
    goodGay(&building);
}

int main(){
    test01();

    system("pause");
    return 0;
}