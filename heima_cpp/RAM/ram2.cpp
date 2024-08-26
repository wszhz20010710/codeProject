#include <iostream>

// 栈区
// 不要返回局部变量的地址
using namespace std;

int * func()
{
    int a = 10; // 局部变量
    return &a;
}

int main()
{
    int * p = func();

    cout << *p << endl;

    system("pause");
    return 0;
}