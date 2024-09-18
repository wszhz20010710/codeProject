#include <iostream>
using namespace std;

// 函数重载的注意事项
// 1.引用作为重载的条件
void fun(int &a) // int &a = 10; 不合法
{
    cout << "fun(int &a)调用" << endl;
}

void fun(const int &a) // const int &a = 10; 合法
{
    cout << "fun(const int &a)调用" << endl;
}
// 2.函数重载碰到默认参数
void fun2(int a, int b) // int &a = 10; 不合法
{
    cout << "fun2(int a, int b)调用" << endl;
}

void fun2(int a) // int &a = 10; 不合法
{
    cout << "fun2(int a)调用" << endl;
}
int main()
{
    // int a = 10;
    // fun(a);
    // fun(10);
    fun2(10);


    system("pause");
    return 0;
}