#include <iostream>

using namespace std;

// 发现是引用 转换为 int* const ref = &a
void func(int &ref)
{
    ref = 100; // ref是引用，转换为*ref = 100
}

int main()
{
    int a = 10;
    
    // 自动转换为int * const ref = &a
    // 指针常量是指针指向不可改，引用也不可改
    int& ref = a;
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;

    ref = 20; // 发现ref是引用，转换为*ref = 20

    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;

    func(a);
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;
    
    system("pause");
    return 0;
}