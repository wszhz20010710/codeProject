#include <iostream>

using namespace std;

void show_value(const int &val)
{
    // val = 1000;
    cout << "val = " << val << endl;
}

int main()
{
    // 常量引用

    // 使用场景：用来修饰形参，防止误操作
    // int a = 10;

    // 加上const 编译器执行 int temp = 10; const int & ref = temp;
    const int & ref = 10; // 引用必须引一块合法空间
    // ref = 10; // 加入const后变为只读，不可修改

    int a = 100;
    show_value(a);

    cout << "a = " << a << endl;
    system("pause");
    return 0;
}

