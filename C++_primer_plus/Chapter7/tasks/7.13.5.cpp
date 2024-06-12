#include <iostream>

using namespace std;

int multiply(int x);

int main()
{
    cout << "输入一个整数程序返回阶乘: ";
    int x;
    while ((cin >> x) && (x <= 15))
    {
        if (x == 114514)
            break;
        cout << x << "! = " << multiply(x) << endl;
        cout << "输入一个整数程序返回阶乘: ";
    }
    return 0;
}

int multiply(int x)
{
    if (x == 0 || x == 1)
    {
        return 1;
    }
    return x * multiply(x-1);
}