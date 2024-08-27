#include <iostream>

using namespace std;
// 引用作为函数返回值
// 1.不要返回局部变量的引用
// int& test01()
// {
//     int a = 10; // 存放在栈区
//     return a;
// }

// 2.函数的调用可以作为左值存在
int& test02()
{
    static int a = 10; // 存放在全局区
    return a;
}
int main()
{
    // int &ref1 = test01();

    // cout << "ref = " << ref << endl;
    // cout << "ref = " << ref << endl;

    int &ref2 = test02();

    cout << "ref = " << ref2 << endl;
    cout << "ref = " << ref2 << endl;
    cout << "ref = " << ref2 << endl;

    // 如果函数的返回值是引用，这个函数调用可以作为左值
    test02() = 1000; // a = 1000, ref2是a的别名， ref = a = 1000
    cout << "ref = " << ref2 << endl;
    cout << "ref = " << ref2 << endl;



    system("pause");
    return 0;
}