#include <iostream>

using namespace std;

// 引用作为函数参数

// 交换函数

// 1.值传递
void my_swap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
// 2.地址传递
void my_swap02(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "a = " << *a << endl;
    cout << "b = " << *b << endl;
}
// 3.引用传递
void my_swap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}
int main()
{
    int a = 10;
    int b = 20;

    // my_swap01(a, b); // 值传递，形参不会修饰实参

    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;

    // my_swap02(&a, &b); // 地址传递，形参修饰实参
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;

    my_swap03(a, b); // 引用传递，形参修饰实参
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    




    system("pause");
    return 0;
}