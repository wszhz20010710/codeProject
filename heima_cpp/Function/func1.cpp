#include <iostream>

using namespace std;

// 函数的默认参数

// 如果自己传入数据，就用自己的，否则使用默认值
int func1(int a, int b = 20, int c = 30)
{
    return a + b+  c;
}

// 1.如果某个位置已有默认参数，那么从这个位置往后，从左到右都必须有默认值
// int func2(int a, int b, int c, int d = 10)
// {
//     return a + b + c;
// }

// 2.如果函数声明有默认参数，函数实现就不能有默认参数
int func3(int a = 10, int b = 10);

int func3(int a, int b)
{
    return a + b;
}

int main()
{
    cout << func1(10, 30) << endl;
    cout << func3(10, 10) << endl;

    system("pause");
    return 0;
}