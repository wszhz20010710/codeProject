#include <iostream>
using namespace std;

const double pi = 3.14;

// 封装
// 设计一个圆类，求周长
class Circle
{
    // 访问权限
    // 公共权限
public:

    // 属性
    int r; // raidus

    // 行为
    double calculateZC()
    {
        return 2 * pi * r;
    }
};

int main()
{
    // 创建对象
    // 实例化，通过一个类创建一个对象
    Circle c1;
    // 给属性赋值
    c1.r = 10;

    cout << "圆的周长为：" << c1.calculateZC() << endl;

    system("pause");
    return 0;
}
