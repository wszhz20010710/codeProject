#include <iostream>
#include <string>
using namespace std;

// 函数模板的注意事项
template<class T> // typename可以替换成class
void mySwap(T&a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}
// 1.自动类型推导必须推导出一致的数据类型才可以使用
void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    mySwap(a, b);
    //mySwap(a, c);
    cout << "a = " << a << ", b = " << b << endl;
}
// 2.模板必须要确定出T的数据类型才可以使用
template<class T>
void func()
{
    cout << "func的函数调用" << endl;
}

void test02()
{
    func<int>();
}
int main(){

    //test01();
    test02();

    
    system("pause");
    return 0;
}