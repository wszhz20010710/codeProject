#include <iostream>
#include <string>
using namespace std;

// 普通函数与函数模板的区别

void myPrint(int a, int b)
{
    cout << "调用的普通函数" << endl;
}

template<class T>
void myPrint(T a, T b)
{
    cout << "调用的模板" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
    cout << "调用重载的模板" << endl;
}

void test01()
{
    int a = 10;
    int b = 20;

    // 强制调用模板
    // myPrint<>(a, b);
    // myPrint<>(a, b, 10);

    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2);

}

int main()
{
    test01();

    system("pause");
    return 0;
}