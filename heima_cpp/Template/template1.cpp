#include <iostream>
#include <string>
using namespace std;

// 函数模板

// 实现两个整型交换
void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 实现两个浮点型交换
void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

// 函数模板
template<typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;
    swapInt(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    double c = 1.1;
    double d = 2.2;
    swapDouble(c, d);
    cout << "c = " << c << ", d = " << d << endl;
}

void test02()
{
    // 利用函数模板来实现交换数据
    // 1.自动类型推导
    int a = 10;
    int b = 20;
    mySwap(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    // 2.显式指定类型
    double c = 1.1;
    double d = 2.2;
    mySwap<double>(c, d);
    cout << "c = " << c << ", d = " << d << endl;
}

int main()
{
    test02();

    system("pause");
    return 0;
}