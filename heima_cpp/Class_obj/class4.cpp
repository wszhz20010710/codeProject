#include <iostream>
using namespace std;
// struct和class的区别
class C1
{
    int m_A; // 默认权限是私有
};

struct C2
{
    int m_A; // 默认权限是公共
};

int main()
{
    // struct默认权限是public
    // class默认权限是private
    C1 c1;
    //c1.m_A = 100;
    C2 c2;
    c2.m_A = 100;
    system("pause");
    return 0;
}