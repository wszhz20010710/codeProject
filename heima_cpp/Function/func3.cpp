#include <iostream>
using namespace std;

// 函数重载
// 1.函数重载要在同一个作用域下
void func()
{
    cout << "func的调用" << endl;
}

void func(int a)
{
    cout << "func(int a)的调用!" << endl;
}
// 类型不同
void func(double a)
{
    cout << "func(double a)的调用!" << endl;
}
// 个数不同
void func(double a, int b)
{
    cout << "func(double a, int b)的调用!" << endl;
}
// 顺序不同
void func(int a, double b)
{
    cout << "func(int a, double b)的调用!" << endl;
}

// 函数的返回值不能作为函数重载的条件
// int func(double a, int b)
// {
//     cout << "func(double a, int b)的调用!" << endl;
// }



int main()
{
    func();
    func(10);
    func(3.1);
    func(3.1, 10);
    func(10, 3.1);
    system("pause");
    return 0;
} 