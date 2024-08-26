#include <iostream>

using namespace std;
// c-const g-global l-local
// 全局变量
int g_a = 10;
int g_b = 10;

// const修饰的全局变量，全局常量
const int c_g_a = 10;
const int c_g_b = 10;
int main()
{
    // 全局区

    // 全局变量、静态变量、常量

    // 创建普通局部变量
    int a = 10;
    int b = 10;

    cout << "address of a is " << (long long)&a << endl;
    cout << "address of b is " << (long long)&b << endl;

    cout << "address of g_a is " << (long long)&g_a << endl;
    cout << "address of g_b is " << (long long)&g_b << endl;

    // 静态变量
    static int s_a = 10;
    static int s_b = 10;
    cout << "address of s_a is " << (long long)&s_a << endl;
    cout << "address of s_b is " << (long long)&s_b << endl;

    // 常量
    // 字符串常量
    cout << "address of string const is " << (long long)&"hello world" << endl;

    // const修饰的变量
    // const修饰的全局变量，全局常量
    cout << "address of c_g_a is " << (long long)&c_g_a << endl;
    cout << "address of c_g_b is " << (long long)&c_g_b << endl;

    // const修饰的局部变量
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "address of c_l_a is " << (long long)&c_l_a << endl;
    cout << "address of c_l_b is " << (long long)&c_l_b << endl;
    system("pause");

    return 0;
}